/*
 * ExprList.cpp
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

#include <vector>
#include "ExprList.h"
#include "ExprCoreList.h"
#include <stdio.h>

namespace psi {

ExprList::ExprList() : Expr(new ExprCoreList()) { }

ExprList::ExprList(const SharedPtr<ExprCore> &ptr) : Expr(ptr) { }

//ExprList::ExprList(const ExprListBuilder &el) : Expr(new ExprCoreList()) {
//	ExprCoreList *c_t = static_cast<ExprCoreList *>(m_core.ptr());
//	traverse_expr_builder(c_t, el);
//}

ExprList::ExprList(const Expr &e) : Expr(new ExprCoreList(e)) { }

ExprList::ExprList(std::initializer_list<Expr> exprlist) : Expr(new ExprCoreList()) {
  ExprCoreList* plist = static_cast<ExprCoreList *>(m_core.ptr());
  auto& list = plist->getExprList();
  std::transform(exprlist.begin(), exprlist.end(), std::back_inserter(list),
      [](const Expr& expr) { return expr.getCore(); });
}

ExprList::ExprList(BaseItem &t) : Expr(new ExprCoreList(Expr(t))) {

}

ExprList::ExprList(const Expr &e1, const Expr &e2) : Expr(new ExprCoreList(e1, e2)) { }

// TODO: biswajit
ExprList::ExprList(const ExprTree& tree) : Expr(new ExprCoreList())
{
  ExprCoreList* plist = static_cast<ExprCoreList*>(m_core.ptr());
  auto& list = plist->getExprList();
  
  ExprCoreList* tree_list = static_cast<ExprCoreList*>(tree.getCorePtr());
  std::transform(tree_list->getExprList().begin(), tree_list->getExprList().end(), 
                std::back_inserter(list), [](const Expr& expr) { return expr.getCore(); });
} 

ExprList::~ExprList() { }

//ExprListBuilder ExprList::operator,(const Expr &rhs) {
////	ExprCoreList *c_t = static_cast<ExprCoreList *>(m_core.ptr());yy
//
//	fprintf(stdout, "ExprList::operator,(Expr) %d\n",
//			rhs.getCorePtr()->getOp());
//
////	if (rhs.getCore().ptr()) {
////		if (rhs.getOp() == Expr::List) {
////			fprintf(stdout, "rhs is a list\n");
////			ExprCoreList *rhs_c = static_cast<ExprCoreList *>(rhs.getCorePtr());
////			std::vector<SharedPtr<ExprCore> >::const_iterator it;
////			for (it=rhs_c->getExprList().begin(); it!=rhs_c->getExprList().end(); it++) {
////				c_t->m_exprList.push_back((*it));
////			}
////		} else {
////			c_t->m_exprList.push_back(rhs.getCore());
////		}
////	}
////	return ExprList(m_core); // Hand off our shared pointer
//	return ExprListBuilder();
//}

const std::vector<SharedPtr<ExprCore> > &ExprList::getExprList() const {
	return static_cast<ExprCoreList *>(m_core.ptr())->m_exprList;
}
    
ExprList& ExprList::operator=(const ExprList& other)
{
  if(this != &other)
  {
    auto otherlist = static_cast<ExprCoreList *>(other.m_core.ptr())->m_exprList;
    auto& thislist = static_cast<ExprCoreList *>(this->m_core.ptr())->m_exprList;
    for(auto iter : otherlist)
    {
      thislist.emplace_back(iter);
    }
  }
  return *this;
}

//ExprList ExprList::operator,(const Type &rhs) {
//	ExprCoreList *c_t = static_cast<ExprCoreList *>(m_core.ptr());
//	fprintf(stdout, "ExprList::operator: Type rhs\n");
//	return ExprList(m_core);
//}

void ExprList::append(const Expr &e) {
	std::vector<SharedPtr<ExprCore> > &l = static_cast<ExprCoreList *>(m_core.ptr())->m_exprList;
	l.push_back(e.getCore());
}


/*void ExprList::traverse_expr_tree(ExprCoreList *c_t, const ExprTree& t) {
  ExprCoreList* plist = static_cast<ExprCoreList*>(t.getCorePtr());

  for(auto iter : plist->getExprList())
  {
    ExprCoreList* sublist = static_cast<ExprCoreList*>(t->getCorePtr());
    if(sublist->getExprList().size() == 1)
    {
      c_t->m_exprList.push_back(SharedPtr<ExprCore>(sublist->getExprList().begin()));
    }
    else
    {
      ExprCoreList *c_tp = new ExprCoreList();
      const ExprTree& c_tree = static_cast<ExprTree&>(iter->getCorePtr());
      traverse_expr_tree(c_tp, c_tree);
    }
  }


void ExprList::traverse_expr_builder(ExprCoreList *c_t, const ExprListBuilder &el) {
	if (el.getBuilderList().size() > 0) {
		// List of builders. Must convert each to an ExprCoreList
		// and add it to the list we're building
		std::vector<ExprListBuilder>::const_iterator it;

		for (it=el.getBuilderList().begin(); it!=el.getBuilderList().end(); it++) {
			ExprCoreList *c_tp = new ExprCoreList();

			traverse_expr_builder(c_tp, *it);

			c_t->m_exprList.push_back(SharedPtr<ExprCore>(c_tp));
		}
	} else {
		// List of CoreExpr. Add to the current list
		std::vector<SharedPtr<ExprCore> >::const_iterator it;
		for (it=el.getList().begin(); it!=el.getList().end(); it++) {
			c_t->m_exprList.push_back(*it);
		}
	}

}*/

} /* namespace psi */
