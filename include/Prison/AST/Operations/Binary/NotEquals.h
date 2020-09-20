#ifndef PRISON_AST_OPERATIONS_BINARY_NEQ
#define PRISON_AST_OPERATIONS_BINARY_NEQ

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"
#include "Prison/AST/Types/Bool.h"

using namespace Prison::AST::Types;

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class NotEquals : public virtual Node {
	public:
		NotEquals(Node * l, Node * r) {
			m_type = "equals";
			m_left = l;
			m_right = r;
		};

		virtual Bool & evaluate(Scope * scope) {
			Bool * value = new Bool(m_left->evaluate(scope) != m_right->evaluate(scope));

			return *value;
		};
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
