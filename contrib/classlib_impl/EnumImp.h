#ifndef __ENUM_IMPL_H__
#define __ENUM_IMPL_H__

#include <map>
#include <string>
#include "NamedBaseItemImp.h"
#include "classlib/Enum.h"

namespace pss {
  class EnumImp : public NamedBaseItemImp
  {
    public:
      EnumImp(Enum* master, BaseItemImp::ObjectType t, BaseItem* p);

      const std::map<unsigned int, std::string>& getEnums() const;
      
      unsigned int get_enum_val() const;
      void set_enum_val(unsigned int val);

      bool parse_name_value(const std::string& str);

    private:
      std::map<unsigned int, std::string>  valueNameMap_;
      unsigned int enumVal_;
      unsigned int enumCounter_;
  };
}

#endif //__ENUM_IMPL_H__
