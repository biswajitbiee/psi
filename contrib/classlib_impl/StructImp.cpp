/*
 * Struct.cpp
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

#include "StructImp.h"
#include "ModelImp.h"
#include "ScopeImp.h"
#include "FieldItemImp.h"
#include "api/IField.h"

namespace pss {

Struct::Struct(const Scope &p) :
	BaseItem(new StructImp(this, p.impl())) { }

Struct::Struct(BaseItemImp *imp) : BaseItem(imp) { }

//				m_structType(Struct::Base) {
//	m_super_type = Model::global()->getSuperType(this);
//	setName(Model::global()->getActiveTypeName(this).leaf());
//	m_ctxt = 0;
//	m_hndl = 0;
//}

StructImp::StructImp(
		Struct		*master,
		ScopeImp	*p,
		StructType	t) :
	NamedBaseItemImp(master, BaseItemImp::TypeStruct, p->parent(), ""),
	m_struct_type(t) {
	m_super_type = ModelImp::global()->getSuperType(master);
	setName(ModelImp::global()->getActiveTypeName(master).leaf());
}

Struct::~Struct() {
	// TODO Auto-generated destructor stub
}

StructImp::~StructImp() {
	// TODO Auto-generated destructor stub
}

const TypePathImp &StructImp::getSuperType() const {
	return m_super_type;
}

StructImp::StructType StructImp::getStructType() const {
	return m_struct_type;
}

void Struct::pre_solve() {

}

void Struct::post_solve() {

}

void StructImp::inline_exec_pre(IObjectContext *ctxt, psshandle_t *hndl) {

}

void StructImp::pre_solve() {

}

void StructImp::post_solve() {

}

void StructImp::inline_exec_post() {

}

  psi_api::insthandle_t StructImp::getHandle() {
    if (m_psshandle == psi_api::nullhandle)
    {
      // hopefully I am nested in a container which does have a handle
      // The below cast may not be successful if this item is not used as a field parameter.
      // This might lead to memory corruptions or undesired behavior. We may have a BaseItem's
      // virtual method called "getFieldItem()" which will return null by default and FieldBase
      // will override to return m_field. We will revisit this later.
      BaseItemImp* base_imp = static_cast<BaseItemImp*>(this);
      FieldItemImp* item = static_cast<FieldItemImp*>(base_imp);
      BaseItemImp* p = item->getParent();
      m_psshandle = (psi_api::insthandle_t)item->getAPIField()->getObjValue(p->getHandle());
    }
    return m_psshandle;
  }

//void Struct::inline_exec_pre(IObjectContext *ctxt, psshandle_t *hndl) {
//	m_ctxt = ctxt;
//	m_hndl = hndl;
//}
//
//void Struct::inline_exec_post() {
//	m_ctxt = 0;
//	m_hndl = 0;
//
//}

} /* namespace pss */
