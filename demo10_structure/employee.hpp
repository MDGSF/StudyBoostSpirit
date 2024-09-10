#if !defined(BOOST_SPIRIT_X3_MINIMAL_EMPLOYEE_HPP)
#define BOOST_SPIRIT_X3_MINIMAL_EMPLOYEE_HPP

#include "ast.hpp"
#include "boost/spirit/home/x3.hpp"

namespace client {
///////////////////////////////////////////////////////////////////////////////
//  Our employee parser declaration
///////////////////////////////////////////////////////////////////////////////
namespace parser {
namespace x3 = boost::spirit::x3;
using employee_type = x3::rule<class employee, ast::employee>;
BOOST_SPIRIT_DECLARE(employee_type);
}  // namespace parser

parser::employee_type employee();
}  // namespace client

#endif
