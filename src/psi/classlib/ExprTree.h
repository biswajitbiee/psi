/*
 * ExprTree.h
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
 *  Created on: June 17, 2016
 *      Author: biswajit@cadence.com
 */

#ifndef __EXPR_TREE_H__
#define __EXPR_TREE_H__

#include "Expr.h"
#include <initializer_list>

namespace psi {
  class ExprTree : public Expr
  {
    public:
      ExprTree();
      ExprTree(const Expr& expr);
      ExprTree(std::initializer_list<Expr> exprlist);

      void add(const Expr& item);
  };
}
#endif //__EXPR_TREE_H__
