#ifndef __EXTEND_IMPL_H__
#define __EXTEND_IMPL_H__

#include "api/IExtend.h"
#include "api/IEnum.h"

namespace psi_api {
  typedef std::map<unsigned int, std::string> enumMapT;
  class ExtendEnumImpl : public IExtend, public IEnum {
    public:
      ExtendEnumImpl(const std::string& name, const enumMapT& enummap);
    
      IExtend::ExtendType getExtendType() const { return IExtend::ExtendType_Enum; };
      IBaseItem *getTarget() const { return nullptr; };

      const std::string &getName() const override { return name_; }; 

      ItemType getType() const override { return IBaseItem::TypeExtend; };
      IBaseItem *clone() { return nullptr; };
      IBaseItem *getParent() const { return parent_; };
      void setParent(IBaseItem *it) { parent_ = it; };
      
      const std::vector<IBaseItem *> &getItems() const { return items_; };
      void add(IBaseItem *item) {};
      
      const enumMapT& getEnums() const { return enumMap_; };

    private:
      IBaseItem*  parent_;
      enumMapT    enumMap_;
      std::string name_;
      std::vector<IBaseItem*> items_; //Not used
  };
}

#endif //__EXTEND_IMPL_H__
