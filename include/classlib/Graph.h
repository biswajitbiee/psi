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
#include "classlib/BaseItem.h"
#include "classlib/Constraint.h"
#include "classlib/ExprList.h"
#include "classlib/ExprTree.h"

namespace pss {

class Graph : public BaseItem {

	public:
    
    Graph(BaseItem *p);

    template<typename... Targs>
      Graph(BaseItem *p, const Targs&... args) : Graph(p)
      {
        add(args...);
      }

		virtual ~Graph();
    
    void add_item(const Constraint& c);
    void add_item(const Expr& e);
    void add();

    template<typename T, typename... Rest>
      void add(const T& item, const Rest&... rest)
      {
        add_item(item);
        add(rest...);
      }
};

} /* namespace pss */

#endif /* GRAPH_H_ */
