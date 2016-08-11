using namespace pss;
#define pss_enum(class_name, ...) \
  class class_name : public Enum { \
    public: \
            enum __pss_##class_name { \
              __VA_ARGS__ \
            }; \
    class_name() : Enum(){ parse_name_value (#__VA_ARGS__); } \
    class_name(__pss_##class_name e) : class_name() { set(e); } \
    class_name(const Scope& p) : Enum(this) { parse_name_value (#__VA_ARGS__); } \
    __pss_##class_name get() const \
    { \
      return Enum::get<__pss_##class_name>(); \
    } \
    void set(__pss_##class_name e) \
    { \
      Enum::set<__pss_##class_name>(e); \
    } \
    class_name& operator=(const __pss_##class_name e) \
    { \
      Enum::operator=(e); \
      return *this; \
    } \
  };

#define pss_enum_ext(class_name, base_class, ...) \
  class class_name : public ExtendEnum<base_class> { \
    public: \
            enum __pss_##class_name { \
              __VA_ARGS__ \
            }; \
    class_name() : ExtendEnum<base_class>(true) \
    { \
      parse_name_value(#__VA_ARGS__); \
    } \
    template<typename T> \
    class_name(const T t) : class_name() \
    { \
      parse_name_value(#__VA_ARGS__); \
      set(t); \
    } \
    class_name(bool b) : ExtendEnum<base_class>(Scope(b)) { parse_name_value (#__VA_ARGS__); } \
    class_name(const Scope& p) : ExtendEnum<base_class>(p) { parse_name_value (#__VA_ARGS__); } \
    __pss_##class_name get() const \
    { \
      return Enum::get<__pss_##class_name>(); \
    } \
    void set(__pss_##class_name e) \
    { \
      Enum::set<__pss_##class_name>(e); \
    } \
    class_name& operator=(const __pss_##class_name e) \
    { \
      Enum::operator=(e); \
      return *this; \
    } \
    using base_class::set; \
    using base_class::get; \
    using base_class::operator=; \
  };
