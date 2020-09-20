#ifndef PRISON_AST_OPERATIONS_BINARY_GEQ
#define PRISON_AST_OPERATIONS_BINARY_GEQ

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"
#include "Prison/AST/Types/Bool.h"

using namespace Prison::AST::Types;

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class GreaterOrEquals : public virtual Node {
	public:
		GreaterOrEquals(Node * l, Node * r) {
			m_type = "greater_or_equals";
			m_left = l;
			m_right = r;
		};

		virtual Bool & evaluate(Scope * scope) {
			Bool * value = new Bool(m_left->evaluate(scope) >= m_right->evaluate(scope));

			return *value;
		};
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
