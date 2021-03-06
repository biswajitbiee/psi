/*
 * Select.h
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
 *  Created on: May 5, 2016
 *      Author: ballance
 */

#ifndef SRC_PSI_CLASSLIB_SELECT_H_
#define SRC_PSI_CLASSLIB_SELECT_H_
#include <vector>
#include "classlib/Types.h"
#include "classlib/Expr.h"
#include "classlib/ExprList.h"

namespace pss {

class Select: public Expr {
public:

	Select(const ExprList &list);

	Select(std::initializer_list<Expr> l) : Select(ExprList(l)) { };

	virtual ~Select();

};

} /* namespace pss */

#endif /* SRC_PSI_CLASSLIB_SELECT_H_ */
