/*
 * ExprCore.cpp
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

#include "classlib/ExprCore.h"
#include "classlib/Expr.h"
#include "classlib/Import.h"

namespace psi {

ExprCore::ExprCore(uint32_t v) : m_op(Expr::LiteralUint) {
	m_val.ui = v;
}

ExprCore::ExprCore(int32_t v) : m_op(Expr::LiteralInt) {
	m_val.i = v;
}

ExprCore::ExprCore(const BaseItem &t) : m_op(Expr::TypeRef) {
	m_val.ref = const_cast<BaseItem*>(&t);
}

ExprCore::ExprCore(Expr::Operator op) : m_op(op) { }

ExprCore::ExprCore(Expr::Operator op, const Expr &lhs, const Expr &rhs) :
  m_op(op), m_lhs(lhs), m_rhs(rhs) {
  }
ExprCore::ExprCore(Expr::Operator op, uint32_t lhs, const Expr &rhs) :
  m_op(op), m_lhs(Expr(lhs)), m_rhs(rhs) {
  }
ExprCore::ExprCore(Expr::Operator op, int32_t lhs, const Expr &rhs) :
  m_op(op), m_lhs(Expr(lhs)), m_rhs(rhs) {
  }
ExprCore::ExprCore(Expr::Operator op, const Expr &lhs, uint32_t rhs) :
  m_op(op), m_lhs(lhs), m_rhs(Expr(rhs)) {
  }
ExprCore::ExprCore(Expr::Operator op, const Expr &lhs, int32_t rhs) :
  m_op(op), m_lhs(lhs), m_rhs(Expr(rhs)) {
  }
ExprCore::ExprCore(Expr::Operator op, int32_t lhs, int32_t rhs) :
  m_op(op), m_lhs(lhs), m_rhs(Expr(rhs)) {
  }
ExprCore::ExprCore(Expr::Operator op, uint32_t lhs, int32_t rhs) :
  m_op(op), m_lhs(Expr(lhs)), m_rhs(Expr(rhs)) {
  }

ExprCore::ExprCore(Import &import, const Expr &params) :
		m_op(Expr::ImportCall), m_lhs(params) {
	m_val.ref = &import;
}

ExprCore::~ExprCore() {
	// TODO Auto-generated destructor stub
}

ExprCore::ExprCore(ExprCore&& rhs)
  : m_val(std::move(rhs.m_val)), m_op(std::move(rhs.m_op))
    , m_lhs(std::move(rhs.m_lhs)), m_rhs(std::move(rhs.m_rhs))
{
  
}

ExprCore& ExprCore::operator=(ExprCore&& rhs)
{
  m_val = std::move(rhs.m_val);
  m_op = std::move(rhs.m_op);
  m_lhs = std::move(rhs.m_lhs);
  m_rhs = std::move(rhs.m_rhs);
}

} /* namespace psi */
