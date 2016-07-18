/*
 * Bind.h
 *
 *  Created on: May 10, 2016
 *      Author: ballance
 */

#ifndef SRC_PSI_CLASSLIB_BIND_H_
#define SRC_PSI_CLASSLIB_BIND_H_
#include <vector>
#include <functional>
#include "Type.h"

namespace psi {

class Bind: public Type {
public:

	Bind(Type *p, const ExprList &stmt);

	ExprList &getStmt() {
		return m_stmt;
	}

/*
	Bind(Type *p, Type &i1);

	Bind(Type *p, Type &i1, Type &i2);

	Bind(Type *p, Type &i1, Type &i2, Type &i3);

	Bind(Type *p, Type &i1, Type &i2, Type &i3, Type &i4);

	Bind(Type *p, Type &i1, Type &i2, Type &i3, Type &i4, Type &i5);

	Bind(Type *p, const std::vector<Type *> &items);
*/

	virtual ~Bind();

	//const std::vector<Type *> &getItems() const { return m_items; }

private:
	ExprList				m_stmt;

	//std::vector<Type *>						m_items;
};

} /* namespace psi */

#endif /* SRC_PSI_CLASSLIB_BIND_H_ */
