#ifndef __EXTEND_ENUM_H__
#define __EXTEND_ENUM_H__
#include "classlib/BaseItem.h"
#include "classlib/ExtendItem.h"
#include "classlib/ExtendEnumBase.h"
#include "classlib/TypeDecl.h"

namespace pss {
  template<typename T>
    class ExtendEnum : public T, public virtual ExtendEnumBase
    {
      public:
        ExtendEnum(const Scope& p) : T(p), e_item_(p, TypeDecl<T>::type_id())
        {
          setExtendedEnumType();
        }

        virtual ~ExtendEnum() {}

        const ExtendItem& getExtendItem() const { return e_item_; }
      
      private:
        ExtendItem e_item_;
    };
}

#endif  //__EXTEND_ENUM_H__
