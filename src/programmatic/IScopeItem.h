/*
 * IScopeItem.h
 *
 *  Created on: May 2, 2016
 *      Author: ballance
 */

#ifndef SRC_PROGRAMMATIC_ISCOPEITEM_H_
#define SRC_PROGRAMMATIC_ISCOPEITEM_H_
#include <vector>
#include "IBaseItem.h"

namespace psi {

	class IScopeItem : public virtual IBaseItem {
	public:

		virtual ~IScopeItem() { }

		virtual const std::vector<IBaseItem *> &getItems() const = 0;

		virtual void add(IBaseItem *item) = 0;

	};
}




#endif /* SRC_PROGRAMMATIC_ISCOPEITEM_H_ */