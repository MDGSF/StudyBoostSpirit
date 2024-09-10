#include <iostream>

#include "boost/spirit/home/x3.hpp"

// Presented are various ways to attach semantic actions
//  * Using plain function pointer
//  * Using simple function object

namespace client {
namespace x3 = boost::spirit::x3;
using x3::_attr;

struct print_action {
  template <typename Context>
  void operator()(Context const& ctx) const {
    std::cout << _attr(ctx) << std::endl;
  }
};
}  // namespace client

int main() {
  using boost::spirit::x3::int_;
  using boost::spirit::x3::parse;
  using client::print_action;

  {  // example using function object

    char const *first = "{43}", *last = first + std::strlen(first);
    parse(first, last, '{' >> int_[print_action()] >> '}');
  }

  {  // example using C++14 lambda

    using boost::spirit::x3::_attr;
    char const *first = "{44}", *last = first + std::strlen(first);
    auto f = [](auto& ctx) { std::cout << _attr(ctx) << std::endl; };
    parse(first, last, '{' >> int_[f] >> '}');
  }

  return 0;
}
