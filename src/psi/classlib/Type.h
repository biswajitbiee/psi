/*
 * Type.h
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
#include "ExprTree.h"
#include "classlib/Expr.h"
#include "classlib/ExprList.h"

#include "api/IBaseItem.h"

namespace psi_api {
    class IField;
};

namespace psi {

class Action;
class Struct;
class Constraint;

class Type {
	friend class Struct;

public:
	enum ObjectType {
		TypeAction,
		TypeBind,
		TypeBit,
		TypeBool,
		TypeChandle,
		TypeComponent,
		TypeConstraint,
		TypeImport,
		TypeInt,
		TypeExec,
		TypeExportAction,
		TypeExtendAction,
		TypeExtendComponent,
		TypeExtendStruct,
		TypeGraph,
		TypePackage,
		TypeString,
		TypeStruct,
		TypeRegistry,
		TypeRef
	};

	enum FieldAttr {
		AttrNone = 0,
		AttrInput,
		AttrOutput,
		AttrLock,
		AttrShare,
		AttrRand,
		AttrPool
	};

	public:

		virtual Type *getParent() const {
			return m_parent;
		}

		inline Type::ObjectType getObjectType() const {
			return m_type;
		}

		inline const std::string &getName() const { return m_name; }

		FieldAttr getAttr() const { return m_attr; }

		void setAttr(FieldAttr attr) { m_attr = attr; }

		inline void setTypeData(Type *t) { m_type_data = t; }

		inline Type *getTypeData() const { return m_type_data; }

		Type *operator ()()  { return this; }

		Expr operator [] (const Expr &rhs);

//		ExprTree operator,(const Type &rhs);

		Expr operator = (const Expr &rhs);

//		Expr operator = (const ExprImportCall &rhs);
  
    operator Expr() const { return Expr(*this); }

		// Effectively private.
		virtual void add(Type *item);

		void setObjectType(Type::ObjectType t);

		virtual const std::vector<Type *> &getChildren() const;

		static const char *toString(ObjectType t);

    virtual Type* createInstance(psi_api::insthandle_t psshandle) {
        // Error! supported only for Action and Struct
        return 0;
    }

    void setAPIField(psi_api::IField* ifld) {
        m_ifld = ifld;
    }

    psi_api::IField* getAPIField();

    virtual void setHandle(psi_api::insthandle_t handle) {}

    virtual psi_api::insthandle_t getHandle() { return psi_api::nullhandle; }
		
    virtual ~Type();
    
    virtual Constraint* get_constraint() { return nullptr; }

    virtual bool has_constraint() const { return false; }

    
	protected:

		Type(Type::ObjectType t, Type *p);

		Type(Type::ObjectType t, Type *p, const std::string &name);

	private:

		bool insideInstance();

	private:
		ObjectType					m_type;
		std::string					m_name;
		Type						*m_parent;


		std::vector<Type *>			m_children;

		// Handle to the declaring type for fields
		Type						*m_type_data;

		FieldAttr					m_attr;

    psi_api::IField * m_ifld;

};

class TypeRef : public Type {
public:
	TypeRef(const std::string &str) : Type(Type::TypeAction, 0) { }
};

} /* namespace psi */

#endif /* TYPE_H_ */
