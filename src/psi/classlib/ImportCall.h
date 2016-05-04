/*
 * ImportCall.h
 *
 *  Created on: Apr 29, 2016
 *      Author: ballance
 */

#ifndef SRC_STATIC_IMPORTCALL_H_
#define SRC_STATIC_IMPORTCALL_H_


namespace psi {

class Import;
class ExprList;
class ImportCall {

	public:

		ImportCall(const Import &imp, const ExprList &plist);

		virtual ~ImportCall();

};

} /* namespace psi */

#endif /* SRC_STATIC_IMPORTCALL_H_ */
