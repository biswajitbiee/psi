/*
 * classlib_native_exec_1.cpp
 *
 *  Created on: May 11, 2016
 *      Author: ballance
 */
#include "pss_tests.h"

int refmodel_get_next_value() {
	return 27;
}

class methods_pkg : public Package {
public:
	pss_package_ctor(methods_pkg);

	Import my_func {this, "my_func",
		{Bit<7,0>("a"), Bit<31,0>("b")}};

	Import my_func2 {this, "my_func2", Bit<7,0>(""),
		{Bit<7,0>("a"), Bit<31,0>("b")}};

};
pss_global_type(methods_pkg);

class top : public Component {
public:
	pss_component_ctor(top);

	class entry_point : public Action {
	public:
		pss_action_ctor(entry_point);

		Rand<Bit<7,0>>		pss_field(p1);
		Rand<Bit<31,0>>		pss_field(p2);
		Rand<Bit<31,0>>		pss_field(p3);
		Field<Bit<31,0>>	pss_field(p4);
		Field<Bit<31,0>>	pss_field(p5);

		Exec pre_solve_e {this, Exec::PreSolve, { p4 } };

		Exec post_solve_e {this, Exec::PostSolve, { p5 } };

		void pre_solve() {
			// Set p4 based on calling a generation-time method
			p4.set(refmodel_get_next_value());
		}

		void post_solve() {
			// Set p5 based on a calculated value
			p5.set(p1.get() + p2.get());
		}
	};
	pss_type(entry_point);

};
pss_global_type(top);


