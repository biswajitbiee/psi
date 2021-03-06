/*
 * IGraphStmt.h
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

#ifndef SRC_PSI_API_IGRAPHSTMT_H_
#define SRC_PSI_API_IGRAPHSTMT_H_

namespace psi_api {

class IGraphStmt {
public:
	enum GraphStmtType {
		/*! Graph block statement. Object is of type IGraphBlockStmt. */
		GraphStmt_Block,
		/*! Graph if/else statement. Object is of type IGraphIfElseStmt.
		 * Used for both top-level if/else and for if-gated select statement */
		GraphStmt_IfElse,
		/*! Graph parallel statement. Object is of type IGraphBlockStmt */
		GraphStmt_Parallel,
		/*! Graph schedule statement. Object is of type IGraphBlockStmt */
		GraphStmt_Schedule,
		//! Graph select statement. Object is of type IGraphBlockStmt
		GraphStmt_Select,
		//! Graph repeat, repeat while, or repeat ... while statement.
		//! Object is of type IGraphRepeatStmt
		GraphStmt_Repeat,

		/*! Graph action-traversal statement */
		GraphStmt_Traverse,

    // For graph constraint block
    GraphStmt_Constraint
	};

public:
	virtual ~IGraphStmt() { }

	virtual GraphStmtType getStmtType() const = 0;

};
}




#endif /* SRC_PSI_API_IGRAPHSTMT_H_ */
