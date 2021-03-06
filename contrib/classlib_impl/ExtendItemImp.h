/*
 * ExtendItem.h
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
 *  Created on: Jul 8, 2016
 *      Author: ballance
 */

#ifndef INCLUDED_EXTEND_ITEM_IMP_H
#define INCLUDED_EXTEND_ITEM_IMP_H

#include "classlib/ExtendItem.h"
#include "BaseItemImp.h"

namespace pss {

class ExtendItemImp: public BaseItemImp {
public:
	ExtendItemImp(
			ExtendItem 				*master,
			BaseItem 				*p,
			BaseItemImp::ObjectType t,
			BaseItem				*type_hndl
			);

	virtual ~ExtendItemImp();

	void setDataType(BaseItem *dt);

	BaseItemImp *getDataType() const { return m_data_type; }

private:

	BaseItemImp				*m_data_type;
};

} /* namespace pss */

#endif /* SRC_PSI_CLASSLIB_EXTENDITEM_H_ */
