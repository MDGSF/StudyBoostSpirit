#if !defined(BOOST_SPIRIT_X3_MINIMAL_AST_HPP)
#define BOOST_SPIRIT_X3_MINIMAL_AST_HPP

#include <iostream>
#include <string>

#include "boost/fusion/include/io.hpp"

namespace client {
namespace ast {
///////////////////////////////////////////////////////////////////////////
//  Our employee AST struct
///////////////////////////////////////////////////////////////////////////
struct employee {
  int age;
  std::string forename;
  std::string surname;
  double salary;
};

using boost::fusion::operator<<;
}  // namespace ast
}  // namespace client

#endif
