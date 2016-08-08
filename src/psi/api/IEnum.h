#ifndef SRC_PSI_API_IENUM_H_
#define SRC_PSI_API_IENUM_H_

#include "api/IBaseItem.h"
#include "api/INamedItem.h"
#include <map>
#include <string>

namespace psi_api {
  class IEnum : public INamedItem, public IBaseItem {
    public:
      virtual ~IEnum() {}

      virtual const std::string &getName() const = 0; 

      virtual ItemType getType() const = 0;
      virtual IBaseItem *clone() = 0;
      virtual IBaseItem *getParent() const = 0;
      virtual void setParent(IBaseItem *it) = 0;

      virtual const std::map<unsigned int, std::string>& getEnums() const = 0;
  };
}

#endif //SRC_PSI_API_IENUM_H_
