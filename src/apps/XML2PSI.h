/*
 * XML2PSI.h
 *
 *  Created on: May 17, 2016
 *      Author: ballance
 */

#ifndef SRC_APPS_XML2PSI_H_
#define SRC_APPS_XML2PSI_H_
#include <expat.h>
#include <stack>
#include <map>
#include "psi_api.h"

using namespace psi_api;

namespace psi {
namespace apps {

class XML2PSI {
public:
	XML2PSI();

	virtual ~XML2PSI();

	virtual void process(const std::string &content, IModel *model);

private:
	typedef std::pair<std::string,std::string> strpair;

	typedef std::map<std::string,std::string> strmap;
	typedef std::pair<std::string,std::string> strmap_ent;

	void enter_action(const strmap &attr);

	void enter_component(const strmap &attr);

	void enter_field(const strmap &attr);

	void enter_package(const strmap &attr);

	void enter_struct(const std::vector<strpair> &attr);

	void enter_struct_type(const strmap &attr);

	static void start(void *data, const char *el, const char **attr) {
		static_cast<XML2PSI *>(data)->start(el, attr);
	}
	void start(const std::string &el, const char **attr);

	static void end(void *data, const char *el) {
		static_cast<XML2PSI *>(data)->end(el);
	}
	void end(const std::string &el);

	IBaseItem *find_type(IScopeItem *curr, const std::vector<std::string> &path);

	std::vector<std::string> split_path(const std::string &path);


private:

	IModel								*m_model;
	std::stack<IBaseItem *>				m_scope_stack;

};

}
} /* namespace psi */

#endif /* SRC_APPS_XML2PSI_H_ */