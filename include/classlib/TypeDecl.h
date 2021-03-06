/*
 * TypeDecl.h
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
 */

#ifndef INCLUDED_TYPE_DECL_H
#define INCLUDED_TYPE_DECL_H
#include <string>
#include <stdio.h>
#include "api/IBaseItem.h"

namespace pss {

template <class T> class TypeDecl : public T {
public:

	TypeDecl(BaseItem *namespace_p=0) : T(Scope(this, namespace_p)) {
		if (!m_type_id) {
			m_valid = true;
			m_type_id = this;
		}
	}

	static T *type_id() {

		if (!m_type_id) {
			m_type_id = new T(true); // anonymous
			// TODO: need to demangle name
			fprintf(stdout, "Error: Object %s is missing type registration\n",
					typeid(T).name());

			// Calling the constructor will set m_valid=true.
			// Flip back, since we aren't actually valid
			m_valid = false;

			// Note that this will result in a non-null (but incorrect)
			// result being returned
		}
		return m_type_id;
	}

	static T *id() { return type_id(); }

	static bool valid() {
		return m_valid;
	}

  BaseItem* Clone() override
  {
    return new T(Scope(this));
  }

private:
	static T 			*m_type_id;
	static bool			m_valid;

};

template <class T> T *TypeDecl<T>::m_type_id = 0;
template <class T> bool TypeDecl<T>::m_valid = false;

}

#endif /* INCLUDED_TYPE_DECL_H */

