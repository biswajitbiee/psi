/*
 * BitType.cpp
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

#include "classlib/BitType.h"
#include "classlib/FieldItem.h"
#include "api/IField.h"

namespace psi {

BitType::BitType(
		BaseItem				*p,
		uint32_t				msb,
		uint32_t				lsb) :
	NamedBaseItem(BaseItem::TypeBit, p), m_msb(msb), m_lsb(lsb) { }

BitType::BitType(
		const std::string		&name,
		uint32_t				msb,
		uint32_t				lsb) :
	NamedBaseItem(BaseItem::TypeBit, 0), m_msb(msb), m_lsb(lsb) {
	//fprintf(stdout, "Error: support BitType::BitType(name)\n");
  setName(name);
}

BitType::~BitType() {
	// TODO Auto-generated destructor stub
}

/*uint64_t BitType::get() {
    //BaseItem* obj = getParent();
    BaseItem* this_item = static_cast<BaseItem*>(this);
    FieldItem* item = static_cast<FieldItem*>(this_item);
    if(!item)
    	std::cout << "NULL" <<std::endl;
    else{
    	std::cout << "BitType::Name " << item->getName() << std::endl;
    	BaseItem* obj = item->getParent();
    psi_api::IField* f = static_cast<psi_api::IField*>(item->getAPIField());
    return f->getIntValue(obj->getHandle());
    }
}*/

//void BitType::set(uint64_t v) {
	// TODO:
//}

} /* namespace psi */
