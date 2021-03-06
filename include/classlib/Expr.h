/*
 * Expr.h
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

#ifndef INCLUDED_EXPR_H
#define INCLUDED_EXPR_H

#include "classlib/Types.h"

namespace pss {

class ExprListBuilder;
class BaseItem;

#define DECLARE_OP_FUNCTIONS(_prefix, _op) \
	_prefix Expr operator _op (const Expr &lhs, const Expr &rhs); \
	_prefix Expr operator _op (const Expr &lhs, int32_t rhs);     \
	_prefix Expr operator _op (const Expr &lhs, uint32_t rhs);    \


class ExprImp;
class Expr {
public:
	friend ExprImp;


		Expr();

		explicit Expr(uint32_t v);

		explicit Expr(int32_t v);

		explicit Expr(const BaseItem &t);

		Expr(const Expr &rhs);
//		Expr(Expr&& rhs);

		explicit Expr(const ExprImp &ptr);

		virtual ~Expr();

 		Expr& operator= (Expr&& rhs);

	Expr operator [] (const Expr &rhs);

	Expr operator [] (int32_t rhs);

	Expr operator [] (uint32_t rhs);

	DECLARE_OP_FUNCTIONS(friend, ==)
	DECLARE_OP_FUNCTIONS(friend, !=)
	DECLARE_OP_FUNCTIONS(friend, <=)
	DECLARE_OP_FUNCTIONS(friend, <)
	DECLARE_OP_FUNCTIONS(friend, >=)
	DECLARE_OP_FUNCTIONS(friend, >)
	DECLARE_OP_FUNCTIONS(friend, &)
	DECLARE_OP_FUNCTIONS(friend, &&)
	DECLARE_OP_FUNCTIONS(friend, |)
	DECLARE_OP_FUNCTIONS(friend, ||)
	DECLARE_OP_FUNCTIONS(friend, -)
	DECLARE_OP_FUNCTIONS(friend, +)
	DECLARE_OP_FUNCTIONS(friend, *)
	DECLARE_OP_FUNCTIONS(friend, /)
	DECLARE_OP_FUNCTIONS(friend, %)

	const ExprImp &imp() const;

protected:
	ExprImp					*m_core;

};

DECLARE_OP_FUNCTIONS( , ==)
DECLARE_OP_FUNCTIONS( , !=)
DECLARE_OP_FUNCTIONS( , <=)
DECLARE_OP_FUNCTIONS( , <)
DECLARE_OP_FUNCTIONS( , >=)
DECLARE_OP_FUNCTIONS( , >)
DECLARE_OP_FUNCTIONS( , &)
DECLARE_OP_FUNCTIONS( , &&)
DECLARE_OP_FUNCTIONS( , |)
DECLARE_OP_FUNCTIONS( , ||)
DECLARE_OP_FUNCTIONS( , -)
DECLARE_OP_FUNCTIONS( , +)
DECLARE_OP_FUNCTIONS( , *)
DECLARE_OP_FUNCTIONS( , /)
DECLARE_OP_FUNCTIONS( , %)

#undef DECLARE_OP_FUNCTIONS


} /* namespace pss */

#endif /* INCLUDED_EXPR_H */
