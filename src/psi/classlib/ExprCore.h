/*
 * ExprCore.h
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
 *  Created on: Apr 27, 2016
 *      Author: ballance
 */

#ifndef SRC_CLASSLIB_EXPRCORE_H_
#define SRC_CLASSLIB_EXPRCORE_H_
#include "classlib/Expr.h"
#include "classlib/BaseItem.h"

namespace psi {

class Import;
class Expr;
class ExprCore {

	public:
		friend class Expr;

		explicit ExprCore(uint32_t v);

		explicit ExprCore(int32_t v);

		explicit ExprCore(const BaseItem &t);

		ExprCore(Expr::Operator op, const Expr &lhs, const Expr &rhs);

		ExprCore(Expr::Operator op, uint32_t lhs, const Expr &rhs);
		ExprCore(Expr::Operator op, int32_t lhs, const Expr &rhs);
		ExprCore(Expr::Operator op, const Expr &lhs, uint32_t rhs);
		ExprCore(Expr::Operator op, const Expr &lhs, int32_t rhs);
		ExprCore(Expr::Operator op, int32_t lhs, int32_t rhs);
		ExprCore(Expr::Operator op, uint32_t lhs, int32_t rhs);

		ExprCore(Import &import, const Expr &params);

		explicit ExprCore(Expr::Operator op);

		virtual ~ExprCore();

    ExprCore(ExprCore&& rhs);
    ExprCore& operator=(ExprCore&& rhs);

		Expr::Operator getOp() const { return m_op; }

		ExprCore *getLhsPtr() const { return m_lhs.getCorePtr(); }

		ExprCore *getRhsPtr() const { return m_rhs.getCorePtr(); }

		uint64_t getValUI() { return m_val.ull; }

		int64_t getValI() { return m_val.i; }

		BaseItem *getTypePtr() const { return m_val.ref; }

		protected:

			union {
				uint64_t			ull;
				int64_t				ll;
				uint32_t			ui;
				int32_t				i;
				BaseItem				*ref;
			} 						m_val;

			Expr::Operator			m_op;

			Expr					m_lhs;
			Expr					m_rhs;

};

} /* namespace psi */

#endif /* SRC_CLASSLIB_EXPRCORE_H_ */
