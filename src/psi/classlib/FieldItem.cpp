/*
 * FieldItem.cpp
 *
 *  Created on: Jul 8, 2016
 *      Author: ballance
 */

#include "FieldItem.h"
#include "api/IField.h"
#include "stdio.h"
namespace psi {

FieldItem::FieldItem(BaseItem *p, const std::string &name) :
		NamedBaseItem(BaseItem::TypeField, p, name),
		m_attr(AttrNone), m_internal(false) , m_ifld(nullptr), m_has_constraint(false) {

}

FieldItem::~FieldItem() {
	// TODO Auto-generated destructor stub
}

uint64_t FieldItem::get() {
    psi_api::IField* f = getAPIField();
    return f->getIntValue(getParent()->getHandle());
}

psi_api::IField* FieldItem::getAPIField() {
	//getchar();
	// The below if check fails though the m_ifld has a value of 0x0, looks like some memory corruption during the prev cast
	// in Struct. Will revisit the code again later.
  //if (m_ifld == nullptr) { // instance meta-objects need to fetch the ifield reference from the type meta-object
	  BaseItem* parent_type_data = this->getParent()->getTypeData();
    for (auto obj_member : parent_type_data->getChildren()) {
    	FieldItem* item = static_cast<FieldItem*>(obj_member);
      if (item->getName().compare(getName())==0 ) {
        	//std::cout << "Name : " << item->getName() << ":" << getName() << std::endl;
        	//std::cout << "Type : " << item->getDataType()->getObjectType() << ":" << this->getObjectType() << std::endl;
        m_ifld = item->m_ifld;
        break;
      }
    }
  //}
  return m_ifld;
}

} /* namespace psi */
