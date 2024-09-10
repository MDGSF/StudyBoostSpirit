#if !defined(BOOST_SPIRIT_X3_MINIMAL_AST_ADAPTED_HPP)
#define BOOST_SPIRIT_X3_MINIMAL_AST_ADAPTED_HPP

#include "ast.hpp"
#include "boost/fusion/include/adapt_struct.hpp"

// We need to tell fusion about our employee struct
// to make it a first-class fusion citizen. This has to
// be in global scope.

BOOST_FUSION_ADAPT_STRUCT(client::ast::employee, age, forename, surname, salary)

#endif
