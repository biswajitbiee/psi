#include "classlib/ExtendEnumBase.h"
#include "BaseItemImp.h"

namespace pss {
  void ExtendEnumBase::setExtendedEnumType()
  {
    BaseItem* b = dynamic_cast<BaseItem*>(this);
    b->impl()->setObjectType(BaseItemImp::TypeExtendEnum);

    //e_item_->impl()->setObjectType(BaseItemImp::TypeExtendEnum);
  }
}
