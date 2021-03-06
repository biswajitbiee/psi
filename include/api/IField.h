/*
 * IField.h
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
 *  Created on: May 5, 2016
 *      Author: ballance
 */

#ifndef SRC_PSI_API_IFIELD_H_
#define SRC_PSI_API_IFIELD_H_
#include <stdint.h>
#include <string>
#include "api/IBaseItem.h"
#include "api/IFieldRef.h"
#include "api/INamedItem.h"

namespace psi_api {

class IField : public IBaseItem, public virtual INamedItem {
public:

	enum FieldAttr {
		FieldAttr_None = 0,
		FieldAttr_Rand,
		FieldAttr_Input,
		FieldAttr_Lock,
		FieldAttr_Output,
		FieldAttr_Pool,
		FieldAttr_Share
	};

public:


	virtual ~IField() { }

	virtual const std::string &getName() const = 0;

	virtual IBaseItem *getDataType() const = 0;

	virtual void setDataType(IBaseItem *type) = 0;

	virtual FieldAttr getAttr() const = 0;

	virtual IExpr *getArrayDim() const = 0;

    virtual int getIntValue(insthandle_t action_handle) const = 0;

    virtual insthandle_t getObjValue(insthandle_t action_handle) const = 0;
};


}




#endif /* SRC_PSI_API_IFIELD_H_ */
