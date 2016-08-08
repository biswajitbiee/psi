#ifndef __EXTEND_ENUM_H__
#define __EXTEND_ENUM_H__
#include "classlib/BaseItem.h"
#include "classlib/ExtendItem.h"
#include "classlib/ExtendBase.h"
#include "classlib/TypeDecl.h"

namespace psi {
  template<typename T>
    class ExtendEnum : public T, public virtual ExtendBase
    {
      public:
        ExtendEnum(const Scope& p) : T(p), e_item_(p, BaseItem::TypeExtendEnum)
        {
          this->setObjectType(BaseItem::TypeExtendEnum);
          e_item_.setDataType(TypeDecl<T>::type_id());
        }

        virtual ~ExtendEnum() {}

        const ExtendItem& getExtendItem() const { return e_item_; }

      private:
        ExtendItem e_item_;
    };
}

#endif  //__EXTEND_ENUM_H__
