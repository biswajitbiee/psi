/*
 * Graph.h
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

#ifndef GRAPH_H_
#define GRAPH_H_
#include "classlib/Type.h"
#include "classlib/Constraint.h"
#include "classlib/ExprList.h"
#include "classlib/ExprTree.h"
#include <initializer_list>

namespace psi {

class Graph : public Type {

	public:
		//Graph(Type *p, const ExprList &seq);
    
    Graph(Type *p) : Type(Type::TypeGraph, p) { }

    template<typename... Targs>
      Graph(Type *p, const Targs&... args) : Type(Type::TypeGraph, p)
      {
        add(args...);
      }

		virtual ~Graph();

		const ExprTree &getExprTree() const { return m_tree; }
		const std::vector<Constraint> &getConstraints() const { return m_constraints; }

  //private:

      void add_item(const Constraint& c)
      {
        m_constraints.emplace_back(c);
      }

      void add_item(const Expr& e)
      {
        m_tree.add(e);
      }
      void add()
      {
      }
    //template<typename T>
      //void add(const T& item)
      //{
        //m_tree.add(item);
      //}

    template<typename T, typename... Rest>
      void add(const T& item, const Rest&... rest)
      {
        //m_tree.add(item);
        add_item(item);
        add(rest...);
      }

	private:
    ExprTree m_tree;
    std::vector<Constraint> m_constraints;
};

} /* namespace psi */

#endif /* GRAPH_H_ */
