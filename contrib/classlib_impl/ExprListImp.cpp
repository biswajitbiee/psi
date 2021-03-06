/*
 * ExprListImp.cpp
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
 *  Created on: May 4, 2016
 *      Author: ballance
 */

#include "classlib/ExprList.h"
#include "ExprCoreList.h"
#include "ExprImp.h"

namespace pss {

ExprList::ExprList() : Expr(ExprImp(new ExprCoreList())) {}

ExprList::ExprList(std::initializer_list<Expr> exprlist) : Expr(ExprImp(new ExprCoreList())) {
  ExprCoreList* plist = static_cast<ExprCoreList *>(m_core->ptr());
  auto& list = plist->getExprList();
  std::transform(exprlist.begin(), exprlist.end(), std::back_inserter(list),
      [](const Expr& expr) { return expr.imp(); });
}

ExprList::~ExprList() {

}

ExprList::ExprList(const Expr &rhs) : Expr(ExprImp(new ExprCoreList())) {
	ExprCoreList *c_t = static_cast<ExprCoreList *>(m_core->ptr());
	c_t->m_exprList.push_back(rhs.imp());
}

ExprList& ExprList::operator=(const ExprList& other)
{
  if(this != &other)
  {
    auto otherlist = static_cast<ExprCoreList *>(other.m_core->ptr())->m_exprList;
    auto& thislist = static_cast<ExprCoreList *>(this->m_core->ptr())->m_exprList;
    for(auto iter : otherlist)
    {
      thislist.emplace_back(iter);
    }
  }
  return *this;
}

/*void traverse_expr_builder(ExprCoreList *c_t, const ExprListBuilderImp &el) {

	if (el.getBuilderList().size() > 0) {
		// List of builders. Must convert each to an ExprCoreList
		// and add it to the list we're building
		std::vector<ExprListBuilderImp>::const_iterator it;

		for (it=el.getBuilderList().begin(); it!=el.getBuilderList().end(); it++) {
			ExprCoreList *c_tp = new ExprCoreList();

			traverse_expr_builder(c_tp, *it);

			c_t->add(ExprImp(c_tp));
		}
	} else {
		// List of CoreExpr. Add to the current list
		std::vector<ExprImp>::const_iterator it;
		for (it=el.getList().begin(); it!=el.getList().end(); it++) {
			c_t->add((*it));
		}
	}
}*/


} /* namespace pss */
