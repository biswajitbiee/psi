/*
 * ExprList.h
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

#ifndef SRC_PSI_CLASSLIB_EXPRLIST_H_
#define SRC_PSI_CLASSLIB_EXPRLIST_H_
#include <vector>
#include <algorithm>
#include <iterator>
#include "classlib/Expr.h"
#include "classlib/ExprTree.h"
#include "classlib/ExprImportCall.h"

namespace psi {

class ExprList : public Expr {
	public:

		ExprList();

		/*template <class T> ExprList(T &first) : Expr(new ExprCoreList()) {
			static_cast<ExprCoreList *>(m_core.ptr())->m_exprList.push_back(Expr(first).getCore());
		}
		template <class T, class... restT> ExprList(T &first, restT & ...rest) :
				ExprList(rest...) {
			std::vector<SharedPtr<ExprCore> > &list = static_cast<ExprCoreList *>(m_core.ptr())->m_exprList;
			list.insert(list.begin(), Expr(first).getCore());
		}*/

    ExprList(std::initializer_list<Expr> exprlist);

		ExprList(const SharedPtr<ExprCore> &ptr);

		ExprList(const Expr &e, const Expr &e2);

		ExprList(const Expr &e);

		ExprList(Type &t);

		ExprList(int v);
		
    ExprList(const ExprTree& tree);

		virtual ~ExprList();

    ExprList& operator=(const ExprList& other);

//		ExprListBuilder operator,(const Expr &rhs);

		const std::vector<SharedPtr<ExprCore> > &getExprList() const;

	private:

		//void traverse_expr_tree(ExprCoreList *c_t, const ExprTree &t);

};

} /* namespace psi */

#endif /* SRC_PSI_CLASSLIB_EXPRLIST_H_ */
