#ifndef PRISON_AST_OPERATIONS_UNARY_MINUS
#define PRISON_AST_OPERATIONS_UNARY_MINUS

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Operations { namespace Unary {

class Minus : public virtual Node {
	public:
		Minus(Node * l) {
			m_left = l;
		};

		virtual Node & evaluate(Scope * scope) {
			return -m_left->evaluate(scope);
		};
};

}}}} // namespace Prison::AST::Operations::Unary

#endif
