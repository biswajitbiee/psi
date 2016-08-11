#include "EnumImpl.h"

namespace psi_api {
  
  EnumImpl::EnumImpl(const std::string& name, const enumMapT& enumMap)
    : parent_(nullptr), enumMap_(enumMap), name_(name)
  {
  }

  const std::string& EnumImpl::getName() const
  {
    return name_;
  }

  const enumMapT& EnumImpl::getEnums() const
  {
    return enumMap_;
  }
}
