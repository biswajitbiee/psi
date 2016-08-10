/*
 * Graph.cpp
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

#include "GraphImp.h"

namespace pss {

  Graph::Graph(BaseItem *p) : BaseItem(new GraphImp(this, p))
  {
  }

  GraphImp::GraphImp(Graph *master, BaseItem *p) :
    BaseItemImp(master, BaseItemImp::TypeGraph, p) { }

  Graph::~Graph() {
    // TODO Auto-generated destructor stub
  }

  GraphImp::~GraphImp() {
    // TODO Auto-generated destructor stub
  }

  const ExprTree& GraphImp::getExprTree() const 
  { 
    return m_tree;
  }
  const std::vector<ConstraintImp*>& GraphImp::getConstraints() const 
  { 
    return m_constraints;
  }

  void GraphImp::add_item(const Constraint& c)
  {
    ConstraintImp* ci = static_cast<ConstraintImp*>(c.impl());
    Constraint* clone = new Constraint(ci->getStmt());
    m_constraints.emplace_back(static_cast<ConstraintImp*>(clone->impl()));
  }

  void GraphImp::add_item(const Expr& e)
  {
    m_tree.add(e);
  }

  void Graph::add_item(const Constraint& c)
  {
    GraphImp* gi = static_cast<GraphImp*>(impl());
    gi->add_item(c);
  }

  void Graph::add_item(const Expr& e)
  {
    GraphImp* gi = static_cast<GraphImp*>(impl());
    gi->add_item(e);
  }
  void Graph::add()
  {
  }
} /* namespace pss */
