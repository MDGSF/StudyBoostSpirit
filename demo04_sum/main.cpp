#include <iostream>
#include <string>

#include "boost/spirit/home/x3.hpp"

namespace client {
namespace x3 = boost::spirit::x3;
namespace ascii = boost::spirit::x3::ascii;

using ascii::space;
using x3::_attr;
using x3::double_;

template <typename Iterator>
bool adder(Iterator first, Iterator last, double& n) {
  auto assign = [&](auto& ctx) { n = _attr(ctx); };
  auto add = [&](auto& ctx) { n += _attr(ctx); };

  bool r = x3::phrase_parse(first, last,

                            //  Begin grammar
                            (double_[assign] >> *(',' >> double_[add])),
                            //  End grammar

                            space);

  if (first != last)  // fail if we did not get a full match
    return false;
  return r;
}
}  // namespace client

int main() {
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tA parser for summing a list of numbers...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout << "Give me a comma separated list of numbers.\n";
  std::cout << "The numbers are added using Phoenix.\n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str)) {
    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    double n;
    if (client::adder(str.begin(), str.end(), n)) {
      std::cout << "-------------------------\n";
      std::cout << "Parsing succeeded\n";
      std::cout << str << " Parses OK: " << std::endl;

      std::cout << "sum = " << n;
      std::cout << "\n-------------------------\n";
    } else {
      std::cout << "-------------------------\n";
      std::cout << "Parsing failed\n";
      std::cout << "-------------------------\n";
    }
  }

  std::cout << "Bye... :-) \n\n";
  return 0;
}
