#if !defined(BOOST_SPIRIT_X3_MINIMAL_EMPLOYEE_DEF_HPP)
#define BOOST_SPIRIT_X3_MINIMAL_EMPLOYEE_DEF_HPP

#include "ast.hpp"
#include "ast_adapted.hpp"
#include "boost/spirit/home/x3.hpp"
#include "employee.hpp"

namespace client {
///////////////////////////////////////////////////////////////////////////////
//  Our employee parser definition
///////////////////////////////////////////////////////////////////////////////
namespace parser {
namespace x3 = boost::spirit::x3;
namespace ascii = boost::spirit::x3::ascii;

using ascii::char_;
using x3::double_;
using x3::int_;
using x3::lexeme;
using x3::lit;

x3::rule<class employee, ast::employee> const employee = "employee";

auto const quoted_string = lexeme['"' >> +(char_ - '"') >> '"'];

auto const employee_def = lit("employee") >> '{' >> int_ >> ',' >>
                          quoted_string >> ',' >> quoted_string >> ',' >>
                          double_ >> '}';

BOOST_SPIRIT_DEFINE(employee);
}  // namespace parser

parser::employee_type employee() { return parser::employee; }
}  // namespace client

#endif
