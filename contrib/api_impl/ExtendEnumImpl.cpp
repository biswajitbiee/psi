#include "ExtendEnumImpl.h"

namespace psi_api {
  ExtendEnumImpl::ExtendEnumImpl(const std::string& name, const enumMapT& enummap)
  : name_(name), enumMap_(enummap)
  {
    items_.clear();
  }
}
