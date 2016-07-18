/*
 * IGraphConstraintStmt.h
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
 *  Created on: July 9, 2016
 *      Author: biswajit
 */

#ifndef __I_GRAPH_CONSTRAINT_STMT_H__
#define __I_GRAPH_CONSTRAINT_STMT_H__
#include "IGraphStmt.h"
#include "IConstraint.h"
#include <vector>

namespace psi_api {
  class IGraphConstraintStmt : public IGraphStmt 
  {
    public:
      virtual ~IGraphConstraintStmt() {}
      virtual void add(IConstraint* c) = 0;
      virtual const std::vector<IConstraint*> &getConstraints() const = 0;
  };
}

#endif //__I_GRAPH_CONSTRAINT_STMT_H__
