/*
 * ExprCoreIf.cpp
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

#include "ExprCoreIf.h"

namespace pss {

ExprCoreIf::ExprCoreIf(const Expr &cond, const Expr &true_expr) :
	ExprCore(ExprImp::Stmt_If, cond, true_expr) { }

ExprCoreIf::ExprCoreIf(const Expr &cond, const Expr &true_expr, const Expr &false_expr) :
	ExprCore(ExprImp::Stmt_IfElse, cond, true_expr), m_false_stmt(false_expr) { }

ExprCoreIf::~ExprCoreIf() {
	// TODO Auto-generated destructor stub
}

} /* namespace pss */
