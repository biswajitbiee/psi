#include "psi_tests.h"

#include <iostream>
#include <cassert>

using namespace psi;

psi_enum(enum_base, ZERO, TWO = 2, THREE)
psi_global_type(enum_base);
psi_enum_ext(enum_ext, enum_base, ONE = 1, FOUR = 4)
psi_global_type(enum_ext);
psi_enum_ext(enum_ext_ext, enum_ext, FIVE = 5, SIX)
psi_global_type(enum_ext_ext);

class comp : public Component
{
  psi_ctor(comp, Component);

  psi_enum(enum_base2, RED, BLUE=5, GREEN)
  psi_type(enum_base2);
};
psi_global_type(comp);

/*int main(int, char**) {

  enum_base b1{enum_base::ZERO};
  enum_base2 b2;

  b1.set(enum_base::TWO);
  b2 = enum_base2::ZERO;
  b1 = enum_base::TWO;
  assert(enum_base::TWO == b1.get());
  assert(enum_base2::ZERO == b2.get());

  b1 = enum_base::ZERO;
  b2 = enum_base2::ZERO;

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
}*/

