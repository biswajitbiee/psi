/*
 * BaseItem.h
 *
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
 *
 *  Created on: Apr 24, 2016
 *      Author: ballance
 */

#ifndef INCLUDED_BASE_ITEM_H
#define INCLUDED_BASE_ITEM_H
#include <string>
#include <vector>

#include "classlib/Expr.h"
#include "classlib/ExprList.h"
#include "classlib/ExprListBuilder.h"
#include "api/IBaseItem.h"

namespace pss {
class Action;
class Struct;
class Constraint;

class BaseItemImp;
class BaseItem {
  friend class BaseItemImp;
public:

	BaseItem *operator ()();

	Expr operator [] (const Expr &rhs);

	Expr operator = (const Expr &rhs);

	operator Expr() const { return Expr(*this); }

	virtual ~BaseItem();

	BaseItemImp *impl() const;
    
protected:

		BaseItem(BaseItemImp *impl);

    virtual BaseItem* Clone() { return nullptr; };

protected:
		BaseItemImp				*m_impl;

};

} /* namespace pss */

#endif /* INCLUDED_BASE_ITEM_H */
