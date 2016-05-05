/*
 * INamedItem.h
 *
 *  Created on: Apr 25, 2016
 *      Author: ballance
 */

#ifndef SRC_PROGRAMMATIC_INAMEDITEM_H_
#define SRC_PROGRAMMATIC_INAMEDITEM_H_
#include <string>

namespace psi_api {

	class INamedItem {
		public:

			virtual ~INamedItem() { }

			virtual const std::string &getName() const = 0;
	};
}



#endif /* SRC_PROGRAMMATIC_INAMEDITEM_H_ */
