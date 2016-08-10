/*
 * FieldItem.cpp
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
 *  Created on: Jul 8, 2016
 *      Author: ballance
 */

#include "FieldItemImp.h"
#include "api/IField.h"
#include <iostream>

namespace pss {

FieldItem::FieldItem(
		BaseItem 				*p,
		const std::string 		&name,
		const Expr				*array_dim,
		FieldItem::FieldAttr 	attr,
		BaseItem				*wrapper,
		BaseItem				*type_hndl) :
		BaseItem(new FieldItemImp(this, p, name, array_dim, attr, wrapper, type_hndl))
  {
}

FieldItemImp::FieldItemImp(
		FieldItem 				*master,
		BaseItem 				*p,
		const std::string 		&name,
		const Expr				*array_dim,
		FieldItem::FieldAttr	attr,
		BaseItem				*wrapper,
		BaseItem				*type_hndl) :
	NamedBaseItemImp(master, BaseItemImp::TypeField, p, name),
		m_data_type(0), m_attr(attr), m_internal(false),
		m_has_array_dim(array_dim!=0),
		m_array_dim((array_dim)?array_dim->imp():ExprImp(0)), m_ifld(nullptr)
{
	setDataType((type_hndl)?type_hndl:wrapper);
	NamedBaseItemImp *wrapper_ni = NamedBaseItemImp::to(wrapper->impl());

	// Change the name of the field base-class object to match the field name
	if (wrapper_ni) {
		wrapper_ni->setName(name);
	}

	// re-home the field base-class object
	toImp(wrapper)->setParent(p);
	toImp(wrapper)->setTypeData(type_hndl);
}

FieldItem::~FieldItem() {
	// TODO Auto-generated destructor stub
}

FieldItemImp::~FieldItemImp() {
	// TODO Auto-generated destructor stub
}

void FieldItemImp::setDataType(BaseItem *dt) {
	m_data_type = toImp(dt);
}

void FieldItem::set_constraint(const Constraint& c)
{
  FieldItemImp* fi = static_cast<FieldItemImp*>(impl());
  fi->set_constraint(c);
}

void FieldItemImp::set_constraint(const Constraint& c)
{
  ConstraintImp* ci = static_cast<ConstraintImp*>(c.impl());
  Constraint* clone = new Constraint(ci->getStmt());
  m_constraint = static_cast<ConstraintImp*>(clone->impl());
}

uint64_t FieldItem::get()
{
  FieldItemImp* fi = static_cast<FieldItemImp*>(impl());
  return fi->get();
}

uint64_t FieldItemImp::get()
{
  psi_api::IField* f = getAPIField();
  uint64_t val = f->getIntValue(getParent()->getHandle());
  return val;
}

psi_api::IField* FieldItemImp::getAPIField()
{
  // The below if check fails though the m_ifld has a value of 0x0, looks like some memory corruption during the prev cast
  // in Struct. Will revisit the code again later.
  //if (m_ifld == nullptr) { // instance meta-objects need to fetch the ifield reference from the type meta-object
  BaseItem* parent_type_data = this->getParent()->getTypeData();
  for (auto obj_member : parent_type_data->impl()->getChildren()) {
    FieldItemImp* item = static_cast<FieldItemImp*>(obj_member);
    if (item->getName().compare(getName())==0 ) {
      //std::cout << "Name : " << item->getName() << ":" << getName() << std::endl;
      //std::cout << "Type : " << item->getDataType()->getObjectType() << ":" << this->getObjectType() << std::endl;
      m_ifld = item->m_ifld;
      break;
    }
  }
  //}
  return m_ifld;
}

} /* namespace pss */
