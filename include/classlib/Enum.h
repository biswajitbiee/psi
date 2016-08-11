#ifndef __ENUM_BASE_H__
#define __ENUM_BASE_H__

#include <string>
#include "classlib/BaseItem.h"
#include "classlib/Scope.h"

namespace pss {
  class Enum : public BaseItem
  {
    public:
      template<typename T>
        T get() const
        {
          return static_cast<T>(get_enum_val_internal());
        }

      template<typename T>
        void set(T t)
        {
          set_enum_val_internal(static_cast<unsigned int>(t));
        }

      template<typename T>
        bool operator==(const T t) const
        {
          return (static_cast<unsigned int>(t) == get_enum_val_internal());
        }

      template<typename T>
        Enum& operator=(const T& t)
        {
          set(t);
          return *this;
        }

      friend std::ostream& operator << (std::ostream& os, const Enum& eb);
    
    protected:
      Enum(const Scope& p);
      Enum();
      
      bool parse_name_value(const std::string& str); 

    private:
      unsigned int get_enum_val_internal() const;
      void set_enum_val_internal(unsigned int val);
  };
}
#endif //__ENUM_BASE_H__
