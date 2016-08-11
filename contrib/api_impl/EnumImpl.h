#ifndef __ENUM_IMPL_H__
#define __ENUM_IMPL_H__

#include "api/IEnum.h"

namespace psi_api {
  typedef std::map<unsigned int, std::string> enumMapT;
  class EnumImpl : public IEnum
  {
    public:
      EnumImpl(const std::string& name, const enumMapT& enumMap);
      virtual const std::string &getName() const override;

      virtual ItemType getType() const { return IBaseItem::TypeEnum; }
      virtual IBaseItem *clone(){ return nullptr; }
      virtual IBaseItem *getParent() const{ return parent_; }
      virtual void setParent(IBaseItem* parent) { parent_ = parent; }

      virtual const enumMapT& getEnums() const override;

    private:
      IBaseItem*  parent_;
      enumMapT    enumMap_;
      std::string name_;
  };
}

#endif //__ENUM_IMPL_H__


