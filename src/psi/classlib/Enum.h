#ifndef __ENUM_BASE_H__
#define __ENUM_BASE_H__

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include "string_util.h"
#include "classlib/NamedBaseItem.h"
#include "classlib/Scope.h"
#include "classlib/Model.h"

namespace psi {
  class Enum : public NamedBaseItem
  {
    protected:
      /*  template<typename T>
          Enum(const T& t) : enumCounter_(0)
          {
          enumVal_ = static_cast<unsigned int>(t);
          }
          */
      Enum(const Scope& p) : NamedBaseItem(BaseItem::TypeEnum, p.parent()) 
      {
        //m_super_type = Model::global()->getSuperType(this);
        //m_ctxt = 0;

        TypePath type = Model::global()->getActiveTypeName(this);
        setName(type.leaf());
      }

      Enum() : NamedBaseItem(BaseItem::TypeEnum, nullptr), enumCounter_(0)
      {
      }

      bool parse_name_value(const std::string& str)
      {
        auto list = StringUtil::split(str, ',');
        for (auto pairStr : list)
        {
          auto pair = StringUtil::get_pair(pairStr, '=');

          unsigned int value = enumCounter_;
          if (pair.second.length() > 0)
          {
            value = atoi(pair.second.c_str());
            enumCounter_ = value;
          }
          enumCounter_++;

          auto iter = valueNameMap_.find(value);
          if(iter == valueNameMap_.end())
          {
            valueNameMap_[value] = pair.first;
          }
          else
          {
            //TODO:: Error
          }
        }
      }

    public:
      template<typename T>
        T get() const
        {
          return static_cast<T>(enumVal_);
        }

      template<typename T>
        void set(T t)
        {
          enumVal_ = static_cast<unsigned int>(t);
        }

      template<typename T>
        bool operator==(const T t) const
        {
          return (static_cast<unsigned int>(t) == enumVal_);
        }

      template<typename T>
        Enum& operator=(const T& t)
        {
          set(t);
          return *this;
        }

      friend std::ostream& operator << (std::ostream& os, const Enum& eb)
      {
        auto iter = eb.valueNameMap_.find(eb.enumVal_);
        if(iter == eb.valueNameMap_.end())
        {
          os << "Error::Value not found!!";
        }
        else
        {
          os << (*iter).second;
        }
        return os;
      }

      const std::map<unsigned int, std::string>& getEnums() const
      {
        return valueNameMap_;
      }

    private:
      std::map<unsigned int, std::string>  valueNameMap_;
      unsigned int enumVal_;
      unsigned int enumCounter_;
  };
}
#endif //__ENUM_BASE_H__
