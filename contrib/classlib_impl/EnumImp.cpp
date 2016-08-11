#include "EnumImp.h"
#include "string_util.h"
#include "ModelImp.h"
#include "TypePathImp.h"
#include "ScopeImp.h"

  namespace pss {
    Enum::Enum(const Scope& p) : BaseItem(new EnumImp(this, BaseItemImp::TypeEnum, p.impl()->parent())) 
    {
    }

    Enum::Enum() : BaseItem(new EnumImp(this, BaseItemImp::TypeEnum, nullptr))
    {
    }
    
    EnumImp::EnumImp(Enum* master, BaseItemImp::ObjectType t, BaseItem* p) :
      NamedBaseItemImp(master, t, p, ""), enumCounter_(0)
    {
      TypePathImp type = ModelImp::global()->getActiveTypeName(master);
      setName(type.leaf());
    }

    bool Enum::parse_name_value(const std::string& str)
    {
      return static_cast<EnumImp*>(impl())->parse_name_value(str);
    }

    bool EnumImp::parse_name_value(const std::string& str)
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
    
    const std::map<unsigned int, std::string>& EnumImp::getEnums() const
    {
      return valueNameMap_;
    }

    std::ostream& operator << (std::ostream& os, const Enum& eb)
    {
      EnumImp* ei = static_cast<EnumImp*>(eb.impl());
      auto enum_map = ei->getEnums();
      auto iter = enum_map.find(ei->get_enum_val());
      if(iter == enum_map.end())
      {
        os << "Error::Value not found!!";
      }
      else
      {
        os << (*iter).second;
      }
      return os;
    }

    unsigned int Enum::get_enum_val_internal() const
    {
      return static_cast<EnumImp*>(impl())->get_enum_val();
    }

    void Enum::set_enum_val_internal(unsigned int val)
    {
      static_cast<EnumImp*>(impl())->set_enum_val(val);
    }

    unsigned int EnumImp::get_enum_val() const
    {
      return enumVal_;
    }

    void EnumImp::set_enum_val(unsigned int val)
    {
      enumVal_ = val;
    }
  }
