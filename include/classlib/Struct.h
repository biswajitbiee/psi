/*
 * Struct.h
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
 *  Created on: Apr 23, 2016
 *      Author: ballance
 */

#ifndef INCLUDED_STRUCT_H
#define INCLUDED_STRUCT_H
#include <string>

#include "classlib/BaseItem.h"
#include "classlib/Scope.h"
#include "api/IBaseItem.h"

namespace pss {

class Struct : public BaseItem {

public:

		virtual ~Struct();

	protected:

		Struct(const Scope &p);

		Struct(BaseItemImp *imp);

  public:
		/**
		 * Solver hook method. Enabled by instantiating an inline Exec block
		 * for ExecKind::PreSolve
		 */
		virtual void pre_solve();

		/**
		 * Solver hook method. Enabled by instantiating an inline Exec block
		 * for ExecKind::PostSolve
		 */
		virtual void post_solve();
};

} /* namespace pss */

#endif /* STRUCT_H_ */