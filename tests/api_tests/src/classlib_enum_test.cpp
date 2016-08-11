#include "pss_tests.h"

#include <iostream>
#include <cassert>

using namespace pss;

pss_enum(enum_base, ZERO, TWO = 2, THREE)
pss_global_type(enum_base);
pss_enum_ext(enum_ext, enum_base, ONE = 1, FOUR = 4)
pss_global_type(enum_ext);
pss_enum_ext(enum_ext_ext, enum_ext, FIVE = 5, SIX)
pss_global_type(enum_ext_ext);

int enum_test();

class pss_top : public Component
{
  pss_ctor(pss_top, Component);

  pss_enum(enum_base2, RED, BLUE=5, GREEN)
  pss_type(enum_base2);
  Rand<enum_ext_ext> pss_field(e_ext_ext);

  class SubAction : public Action {
  public:
    pss_ctor(SubAction, Action);
    
    Rand<enum_base> pss_field(e);
    Rand<enum_ext> pss_field(e_ext);

    Constraint c {this, e_ext <= enum_ext_ext::THREE};

    enum_ext_ext e1{enum_base::THREE};
    const int i = enum_test();

    virtual void pre_solve() {
      std::cout << "Hi from Subaction::pre_solve, setting local var enum value to FIVE" << std::endl;
      e1.set(enum_ext_ext::FIVE);
      e1 = enum_ext_ext::FIVE;
    }
    virtual void post_solve() {
      std::cout << "Hi from Subaction::post_solve, asserting that loal var enum value is FIVE" << std::endl;
      assert(e1.get() == enum_ext_ext::FIVE);
      assert(e1 == enum_ext_ext::FIVE);
    }


  };
  pss_type(SubAction);
};
pss_global_type(pss_top);

int enum_test() {

  enum_base b1{enum_base::ZERO};
  pss_top::enum_base2 b2;

  b1.set(enum_base::TWO);
  b2 = pss_top::enum_base2::RED;
  b1 = enum_base::TWO;
  assert(enum_base::TWO == b1.get());
  assert(pss_top::enum_base2::RED == b2.get());

  b1 = enum_base::ZERO;
  b2 = pss_top::enum_base2::GREEN;

  if (b1 == enum_base::ZERO) {
    std::cout << "b1 is " << b1 << std::endl;
  }

  enum_ext b11{enum_ext::TWO};
  b11 = enum_ext::TWO;
  if (b11 == enum_ext::TWO) {
    std::cout << "b11 is " << b11 <<std::endl;
  }
  b11 = enum_ext::FOUR;
  if (b11 == enum_ext::FOUR) {
    std::cout << "b11 is " << b11 <<std::endl;
  }

  enum_ext_ext b111{enum_ext_ext::FOUR};
  b111 = enum_ext_ext::TWO;
  if (b111 == enum_ext_ext::TWO) {
    std::cout << "b111 is " << b111 << std::endl;
  }
  b111 = enum_ext_ext::FOUR;
  if (b111 == enum_ext_ext::FOUR) {
    std::cout << "b111 is " << b111 << std::endl;
  }
  b111 = enum_ext_ext::SIX;
  if (b111 == enum_ext_ext::SIX) {
    std::cout << "b111 is " << b111 << std::endl;
  }

  return 0;
}

//static int i = enum_test();

