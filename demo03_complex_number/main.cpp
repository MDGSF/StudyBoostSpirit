/*
Alternates: e.g. a | b. Try a first. If it succeeds, good. If not, try the next
alternative, b. Optionals: e.g. -p. Match the parser p zero or one time.
*/

#include <complex>
#include <iostream>
#include <string>

#include "boost/spirit/home/x3.hpp"

namespace client {
template <typename Iterator>
bool parse_complex(Iterator first, Iterator last, std::complex<double>& c) {
  using boost::spirit::x3::_attr;
  using boost::spirit::x3::double_;
  using boost::spirit::x3::phrase_parse;
  using boost::spirit::x3::ascii::space;

  double rN = 0.0;
  double iN = 0.0;
  auto fr = [&](auto& ctx) { rN = _attr(ctx); };
  auto fi = [&](auto& ctx) { iN = _attr(ctx); };

  bool r = phrase_parse(
      first, last,

      //  Begin grammar
      ('(' >> double_[fr] >> -(',' >> double_[fi]) >> ')' | double_[fr]),
      //  End grammar

      space);

  if (!r || first != last)  // fail if we did not get a full match
    return false;
  c = std::complex<double>(rN, iN);
  return r;
}
}  // namespace client

int main() {
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tA complex number micro parser for Spirit...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout << "Give me a complex number of the form r or (r) or (r,i) \n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str)) {
    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    std::complex<double> c;
    if (client::parse_complex(str.begin(), str.end(), c)) {
      std::cout << "-------------------------\n";
      std::cout << "Parsing succeeded\n";
      std::cout << "got: " << c << std::endl;
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
