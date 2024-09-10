#include "ast.hpp"
#include "ast_adapted.hpp"
#include "employee.hpp"

int main() {
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tAn employee parser for Spirit...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout << "Give me an employee of the form :"
            << "employee{age, \"forename\", \"surname\", salary } \n";
  std::cout << "Type [q or Q] to quit\n\n";

  using boost::spirit::x3::ascii::space;
  using iterator_type = std::string::const_iterator;
  using client::employee;

  std::string str;
  while (getline(std::cin, str)) {
    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    client::ast::employee emp;
    iterator_type iter = str.begin();
    iterator_type const end = str.end();
    bool r = phrase_parse(iter, end, employee(), space, emp);

    if (r && iter == end) {
      std::cout << boost::fusion::tuple_open('[');
      std::cout << boost::fusion::tuple_close(']');
      std::cout << boost::fusion::tuple_delimiter(", ");

      std::cout << "-------------------------\n";
      std::cout << "Parsing succeeded\n";
      std::cout << "got: " << emp << std::endl;
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
