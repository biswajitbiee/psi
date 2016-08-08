/*
 * BaseItem.h
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
 *
 *  Created on: Apr 24, 2016
 *      Author: ballance
 */

#ifndef TYPE_H_
#define TYPE_H_
#include <string>
#include <vector>

#include "classlib/Expr.h"
#include "classlib/ExprList.h"
#include "classlib/ExprListBuilder.h"

#include "api/IBaseItem.h"

namespace psi_api {
      class IField;
};

namespace psi {

class Action;
class Struct;
class Constraint;

class BaseItem {
	friend class Struct;

public:
	enum ObjectType {
		TypeAction,    // 0
		TypeBind,
		TypeBit,
		TypeBool,
		TypeChandle,
		TypeComponent, // 5
		TypeConstraint,
		TypeImport,
		TypeInt,
		TypeExec,
		TypeExportItem, // 10
		TypeExtendAction,
		TypeExtendComponent,
		TypeExtendStruct,
		TypeField,
		TypeGraph,
		TypePackage,
		TypeString,
		TypeStruct, // 18
		Model, // 19
		TypeRef,
    TypeEnum,
    TypeExtendEnum
	};

	public:

		virtual void setParent(BaseItem *p) {
			m_parent = p;
		}

		virtual BaseItem *getParent() const {
			return m_parent;
		}

		inline BaseItem::ObjectType getObjectType() const {
			return m_type;
		}

		BaseItem *operator ()()  { return this; }

		Expr operator [] (const Expr &rhs);

		Expr operator = (const Expr &rhs);

    	operator Expr() const { return Expr(*this); }

//		Expr operator = (const ExprImportCall &rhs);

		// Effectively private.
		virtual void add(BaseItem *item);

		void setObjectType(BaseItem::ObjectType t);

		virtual const std::vector<BaseItem *> &getChildren() const;

		static const char *toString(ObjectType t);

		virtual ~BaseItem();

    virtual BaseItem* createInstance(psi_api::insthandle_t psshandle) {
      // Error! supported only for Action and Struct
      return 0;
    }

    virtual void setHandle(psi_api::insthandle_t handle) {}

    virtual psi_api::insthandle_t getHandle() { return psi_api::nullhandle; }
    
    void setTypeData(BaseItem* data) { m_meta_data = data; }
    BaseItem*	getTypeData() const { return m_meta_data; }

	protected:

		BaseItem(BaseItem::ObjectType t, BaseItem *p);

		BaseItem(BaseItem::ObjectType t);

	private:

		bool insideInstance();

	private:
		ObjectType					m_type;
		BaseItem					*m_parent;

		std::vector<BaseItem *>		m_children;
		BaseItem*		m_meta_data;
};

class TypeRef : public BaseItem {
public:
	TypeRef(const std::string &str) : BaseItem(BaseItem::TypeAction, 0) { }
};

} /* namespace psi */

#endif /* TYPE_H_ */
