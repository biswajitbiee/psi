/*
 * FieldItem.h
 *
 *  Created on: Jul 8, 2016
 *      Author: ballance
 */

#ifndef SRC_PSI_CLASSLIB_FIELDITEM_H_
#define SRC_PSI_CLASSLIB_FIELDITEM_H_
#include <string>
#include "classlib/NamedBaseItem.h"
#include "classlib/Scope.h"
#include "classlib/Constraint.h"
#include <iostream>

namespace psi_api {
      class IField;
};

namespace psi {

class FieldItem: public NamedBaseItem {
public:
	enum FieldAttr {
		AttrNone = 0,
		AttrInput,
		AttrOutput,
		AttrLock,
		AttrShare,
		AttrRand,
		AttrPool
	};

public:
	FieldItem(BaseItem *p, const std::string &name);

	virtual ~FieldItem();

	BaseItem *getDataType() const { return getTypeData(); }

	void setDataType(BaseItem *dt) { setTypeData(dt); }

	FieldAttr getAttr() const { return m_attr; }

	void setAttr(FieldAttr attr) { m_attr = attr; }

	void setInternal(bool i) { m_internal = i; }

	bool isInternal() const { return m_internal; }

    void setAPIField(psi_api::IField* ifld) {
      m_ifld = ifld;
    }

    uint64_t get();

    psi_api::IField* getAPIField();

  void set_constraint(const Constraint& c)
  {
    m_constraint = c;
    m_has_constraint = true;
  }

  Constraint* get_constraint() { return &m_constraint; }
  bool has_constraint() const { return m_has_constraint; }

private:
	//BaseItem				*m_data_type;
	FieldAttr				m_attr;
	bool					m_internal;
  
	psi_api::IField * m_ifld;

	Constraint m_constraint;
	bool m_has_constraint;


};

} /* namespace psi */

#endif /* SRC_PSI_CLASSLIB_FIELDITEM_H_ */
