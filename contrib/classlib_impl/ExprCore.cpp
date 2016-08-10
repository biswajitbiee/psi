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
 *  Created on: Jul 28, 2016
 *      Author: ballance
 */
#include "ExprCore.h"
#include "classlib/Import.h"

namespace pss {

  ExprCore::ExprCore(uint32_t v) {
    m_val.ui = v;
    m_op = ExprImp::LiteralBit;
  }

  ExprCore::ExprCore(int32_t v) {
    m_val.i = v;
    m_op = ExprImp::LiteralInt;
  }

  ExprCore::ExprCore(const BaseItem &t) {
    m_val.ref = t.impl();
    m_op = ExprImp::TypeRef;
  }

  ExprCore::ExprCore(ExprImp::Operator op) : m_op(op) { }

  ExprCore::ExprCore(ExprImp::Operator op, const Expr &lhs, const Expr &rhs) : 
    m_op(op), m_lhs(lhs.imp()), m_rhs(rhs.imp()) {
    }
  ExprCore::ExprCore(ExprImp::Operator op, uint32_t lhs, const Expr &rhs) :
    m_op(op), m_lhs(Expr(lhs).imp()), m_rhs(rhs.imp()) {
    }
  ExprCore::ExprCore(ExprImp::Operator op, int32_t lhs, const Expr &rhs) :
    m_op(op), m_lhs(Expr(lhs).imp()), m_rhs(rhs.imp()) {
    }
  ExprCore::ExprCore(ExprImp::Operator op, const Expr &lhs, uint32_t rhs) :
    m_op(op), m_lhs(lhs.imp()), m_rhs(Expr(rhs).imp()) {
    }
  ExprCore::ExprCore(ExprImp::Operator op, const Expr &lhs, int32_t rhs) :
    m_op(op), m_lhs(lhs.imp()), m_rhs(Expr(rhs).imp()) {
    }
  ExprCore::ExprCore(ExprImp::Operator op, int32_t lhs, int32_t rhs) :
    m_op(op), m_lhs(Expr(lhs).imp()), m_rhs(Expr(rhs).imp()) {
    }
  ExprCore::ExprCore(ExprImp::Operator op, uint32_t lhs, int32_t rhs) :
    m_op(op), m_lhs(Expr(lhs).imp()), m_rhs(Expr(rhs).imp()) {
    }

  ExprCore::ExprCore(Import &import, const Expr &params) :
    m_op(ExprImp::ImportCall), m_lhs(params) {
      m_val.ref = import.impl();
    }

  ExprCore::~ExprCore() {}

/*  ExprCore::ExprCore(ExprCore&& rhs)
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
*/
}
