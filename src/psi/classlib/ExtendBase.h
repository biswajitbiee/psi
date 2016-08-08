#ifndef __EXTEND_BASE_H__
#define __EXTEND_BASE_H__

#include "classlib/ExtendItem.h"

namespace psi {
  class ExtendBase
  {
    public:
      virtual ~ExtendBase() {}
      virtual const ExtendItem& getExtendItem() const = 0;
  };
}

#endif //__EXTEND_BASE_H__
