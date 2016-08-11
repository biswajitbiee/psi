#ifndef __EXTEND_BASE_H__
#define __EXTEND_BASE_H__

#include "classlib/ExtendItem.h"

namespace pss {
  class ExtendEnumBase
  {
    public:
      virtual ~ExtendEnumBase() {}
      virtual const ExtendItem& getExtendItem() const = 0;

    protected:
      void setExtendedEnumType();
  };
}

#endif //__EXTEND_BASE_H__
