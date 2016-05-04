/*
 * BitType.h
 *
 *  Created on: Apr 23, 2016
 *      Author: ballance
 */

#ifndef BITTYPE_H_
#define BITTYPE_H_
#include <stdint.h>
#include <string>

#include "classlib/Type.h"

namespace psi {

class BitType : public Type {

	public:
		BitType(
				const std::string 	&name,
				Type 				*p,
				uint32_t			msb,
				uint32_t			lsb);

		virtual ~BitType();

};


} /* namespace psi */

#endif /* BITTYPE_H_ */