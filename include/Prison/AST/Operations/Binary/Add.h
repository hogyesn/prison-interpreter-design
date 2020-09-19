#ifndef PRISON_AST_OPERATIONS_BINARY_ADD
#define PRISON_AST_OPERATIONS_BINARY_ADD

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class Add : public virtual Node {
	public:
		Add(Node * l, Node * r) {
			m_type = "addop";
			m_left = l;
			m_right = r;
		};

		virtual Node & evaluate(Scope * scope) {
			return m_left->evaluate(scope) + m_right->evaluate(scope);
		};
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
