#ifndef PRISON_AST_OPERATIONS_BINARY_SUBSTRACT
#define PRISON_AST_OPERATIONS_BINARY_SUBSTRACT

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class Substract : public virtual Node {
	public:
		Substract(Node * l, Node * r) {
			m_type = "subop";
			m_left = l;
			m_right = r;
		};

		virtual Node & evaluate(Scope * scope) {
			return m_left->evaluate(scope) - m_right->evaluate(scope);
		};
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
