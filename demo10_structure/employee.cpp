#include "config.hpp"
#include "employee_def.hpp"

namespace client {
namespace parser {
BOOST_SPIRIT_INSTANTIATE(employee_type, iterator_type, context_type);
}
}  // namespace client
