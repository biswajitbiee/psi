/*
 * Struct.h
 *
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 *  Created on: Apr 23, 2016
 *      Author: ballance
 */

#ifndef STRUCT_H_
#define STRUCT_H_
#include <string>

#include "classlib/NamedBaseItem.h"
#include "classlib/TypePath.h"

namespace psi_api {
	class IObjectContext;
	struct psshandle_t;
}

using namespace psi_api;

namespace psi {

class ResourceStruct;
class StateStruct;
class MemoryStruct;
class StreamStruct;
class Scope;
class Elaborator;
class Struct : public NamedBaseItem {
	friend ResourceStruct;
	friend StateStruct;
	friend MemoryStruct;
	friend StreamStruct;
	friend Elaborator;

public:
	enum StructType {
		Base,
		Memory,
		State,
		Stream,
		Resource
	};

	public:

		virtual ~Struct();

		const TypePath &getSuperType() const { return m_super_type; }

		StructType getStructType() const { return m_structType; }

	    virtual void setHandle(psi_api::insthandle_t handle) { m_psshandle = handle; }

        psi_api::insthandle_t getHandle();

		/**
		 * Solver hook method. Enabled by instantiating an inline Exec block
		 * for ExecKind::PreSolve
		 */
		virtual void pre_solve();

		/**
		 * Solver hook method. Enabled by instantiating an inline Exec block
		 * for ExecKind::PostSolve
		 */
		virtual void post_solve();

		/**
		 * Solver hook method. Enabled by instantiating an inline Exec block
		 * for ExecKind::Body
		 */
		virtual void body();

	protected:
	
	Struct(const Scope &p);


	private:

		virtual void inline_exec_pre(IObjectContext *ctxt, psshandle_t *hndl);

		virtual void inline_exec_post();

		Struct(
				StructType			t,
				BaseItem			*p);

	private:
		StructType						m_structType;
		TypePath						m_super_type;
		IObjectContext					*m_ctxt;
	    psi_api::insthandle_t m_psshandle { psi_api::nullhandle };

};

} /* namespace psi */

#endif /* STRUCT_H_ */
