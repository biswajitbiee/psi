/*
 * IGraphBlockStmt.h
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
 *  Created on: May 8, 2016
 *      Author: ballance
 */

#ifndef SRC_PSI_API_IGRAPHBLOCKSTMT_H_
#define SRC_PSI_API_IGRAPHBLOCKSTMT_H_
#include <vector>
#include "api/IGraphStmt.h"

namespace psi_api {

class IGraphBlockStmt : public IGraphStmt {
public:
	virtual ~IGraphBlockStmt() { }

	virtual const std::vector<IGraphStmt *> &getStmts() const = 0;

	virtual void add(IGraphStmt *stmt) = 0;

};

}




#endif /* SRC_PSI_API_IGRAPHBLOCKSTMT_H_ */
