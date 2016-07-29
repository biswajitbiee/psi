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

#include "classlib/Struct.h"
#include "classlib/Model.h"
#include "classlib/Scope.h"
#include "classlib/FieldItem.h"
#include "api/IField.h"

namespace psi {

Struct::Struct(const Scope &p) : NamedBaseItem(BaseItem::TypeStruct, p.parent()),
				m_structType(Struct::Base) {
	m_super_type = Model::global()->getSuperType(this);
	setName(Model::global()->getActiveTypeName(this).leaf());
	m_ctxt = 0;
}

Struct::Struct(Struct::StructType t, BaseItem *p) :
				NamedBaseItem(BaseItem::TypeStruct, p),
				m_structType(t) {
	m_super_type = Model::global()->getSuperType(this);
	setName(Model::global()->getActiveTypeName(this).leaf());
	m_ctxt = 0;
}

psi_api::insthandle_t Struct::getHandle() {
	if (m_psshandle == psi_api::nullhandle)
	{
		// hopefully I am nested in a container which does have a handle
		BaseItem* this_item = static_cast<BaseItem*>(this);
    // The below cast may not be successful if this item is not used as a field parameter.
    // This might lead to memory corruptions or undesired behavior. We may have a BaseItem's
    // virtual method called "getFieldItem()" which will return null by default and FieldBase
    // will override to return m_field. We will revisit this later.
		FieldItem* item = static_cast<FieldItem*>(this_item);
		m_psshandle = (psi_api::insthandle_t)item->getAPIField()->getObjValue(getParent()->getHandle());
	}
	return m_psshandle;
}

Struct::~Struct() {
	// TODO Auto-generated destructor stub
}

void Struct::pre_solve() {

}

void Struct::post_solve() {

}

void Struct::body() {

}

void Struct::inline_exec_pre(IObjectContext *ctxt, psshandle_t *hndl) {
	m_ctxt = ctxt;
	//m_psshandle = hndl;
}

void Struct::inline_exec_post() {
	m_ctxt = 0;
//	m_psshandle = 0;

}

} /* namespace psi */
