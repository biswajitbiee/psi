/*
 * Node.h
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
 *  Created on: July 13, 2016
 *      Author: biswajit
 */

#ifndef __NODE_H__
#define __NODE_H__

#include "classlib/Type.h"
#include "classlib/Constraint.h"
#include "classlib/SharedPtr.h"

namespace psi {
  template<typename T>
    class Node : public T
    {
      public:
        Node(Type* p, const std::string& name) : T(p, name), m_has_constraint(false)
        {
          Type *t = static_cast<Type *>(this);
          if (t->getObjectType() == Type::TypeAction ||
              t->getObjectType() == Type::TypeStruct ||
              t->getObjectType() == Type::TypeComponent) {
            t->setTypeData(TypeRgy<T>::type_id());
        }
        }

        //SharedPtr<Type> with(const Constraint& c)
        Node<T>& with(const Constraint& c)
        {
          Node<T>* clone = new Node<T>(*this);
          clone->m_has_constraint = true;
          clone->m_constraint = c;
          return *clone;
          //return SharedPtr<Type>(new Node<T>(*this));
        }

        Constraint* get_constraint() override { return &m_constraint; }
        bool has_constraint() const override { return m_has_constraint; }
          
      private:
        Constraint m_constraint;
        bool m_has_constraint;
    };
}

#endif //__NODE_H__
