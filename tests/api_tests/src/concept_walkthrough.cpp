/*
 * concept_walkthrough.cpp
 *
 *  Created on: Apr 23, 2016
 *      Author: ballance
 */
#include "psi.h"
#include <stdio.h>

using namespace psi;

static class data_s : public MemoryStruct {
public:
	Rand<Bit<7,0>>		data    {"data", this};
	Rand<Bit<31,0>>		address {"address", this};

	data_s(
		const std::string 		&name="data_s",
		IConstructorContext 	*p=nullptr) : MemoryStruct(name, p) { }

	Constraint address_c {this, address >= 0x1000 && address <= 0x1FFF};

	// Register this type definition
} data_sT;

static class rw_comp : public Component {
public:

	rw_comp(const std::string &name="rw_comp", IConstructorContext *p=nullptr) : Component(name, p) { }

	class processor_s : public ResourceStruct {
	public:

		processor_s(const std::string &name, IConstructorContext *p) : ResourceStruct(name, p) { }

		Constraint resource_c {this, Expr(instance_id) == 1};

	} processor_sT {"processor_s", this};

	class write_data : public Action {
	public:

		write_data(const std::string &name, IConstructorContext *p) : Action(name, p) { }

		// When instantiating a field of a non-primitive type, a reference
		// to its declaration must be provided. This can be done via a reference
		// to the type-declaration object (data_sT), or with a string name.
		// Note that C++ construction-order rules require us to use the 'string'
		// form for proc, since it's declared in the same component.
		Output<data_s>			out_data	{"out_data", this, data_sT};
		Lock<processor_s>		proc 		{"proc", this, "processor_s"};
	} write_dataT {"write_data", this};

	class read_data : public Action {
	public:

		read_data(const std::string &name, IConstructorContext *p) : Action(name, p) { }

		Input<data_s>			in_data		{"in_data", this, data_sT};
		Lock<processor_s>		proc		{"proc", this, "processor_s"};
	} read_dataT {"read_data", this};

} rw_compT;

static class top_comp : public Component {
public:
	top_comp(const std::string name="top_comp", IConstructorContext *p=nullptr) : Component(name, p) { }

	class my_test2 : public Action {
	public:

		my_test2(const std::string &name, IConstructorContext *p) : Action(name, p) { }

		// Action instance needs to know the details of its type. This is
		// provided via a type-definition reference (eg _rw_comp._write_data)
		Field<rw_comp::write_data>		wd1 {"wd1", this, rw_compT.write_dataT};
		Field<rw_comp::read_data>		rd1 {"rd1", this, rw_compT.read_dataT};
		Field<rw_comp::write_data>		wd2 {"wd2", this, rw_compT.write_dataT};
		Field<rw_comp::read_data>		rd2 {"rd2", this, rw_compT.read_dataT};

			// TODO: Bind -- make static?

//#ifdef UNDEFINED
//			my_test2() {
//				bind(wd1.out_data, rd1.in_data);
//				bind(wd2.out_data, rd1.in_data);
//			};
//
//			// Only a single graph is permitted per action
//			Graph graph {
//				wd1, rd1, wd2, rd2,
//	//			select {
//	//
//	//			}
//			};
//
		Constraint addr_c {this, rd1.in_data.address != rd2.in_data.address };

	} my_test2T {"my_test2", this}; // Complete registration of this type

} top_compT;

static class c_methods : public Package {
public:

	c_methods() : Package("c_methods") { }

	// Prototypes for import functions
	Import do_write {"do_write", this,
		(Bit<31,0>("addr"), Bit<31,0>("data"))
	};

	Import do_check {"do_check", this,
		(Bit<31,0>("addr"), Bit<31,0>("data"))
	};

} c_methodsT;

static class c_code : public Package {
public:

	c_code() : Package("c_code") { }

	// Declares an extension of 'write_data' to layer in the implementation
	class write_data_ext : public ExtendAction<rw_comp::write_data> {
	public:

		write_data_ext(IConstructorContext *p, rw_comp::write_data &t_ref) : ExtendAction(p, t_ref) { }

		Exec do_write_body {Exec::Body, this, "C", R"(
				do_write({{address}}, {{data}}
				)"
		};

		Exec do_write_body_native {Exec::Body, this,
			c_methodsT.do_write((out_data.address, out_data.data))
		};
	} write_data_extT {this, rw_compT.write_dataT};

	class read_data_ext : public ExtendAction<rw_comp::read_data> {
	public:

		read_data_ext(IConstructorContext *p, rw_comp::read_data &t_ref) : ExtendAction(p, t_ref) {}

		Exec do_check_body_native {Exec::Body, this,
			c_methodsT.do_check((in_data.address, in_data.data))
		};
	};

} c_codeT;


// Ignore: test code
int main(int argc, char **argv) {
	fprintf(stdout, "Hello World\n");
	TypeRegistry::global()->build();
}