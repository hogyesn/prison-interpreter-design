#ifndef PRISON_AST_OPERATIONS_BINARY_ASSIGN
#define PRISON_AST_OPERATIONS_BINARY_ASSIGN

#include "Prison/AST/Node.h"
#include "Prison/AST/Identifier.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class Assign : public virtual Node {
	public:
		Assign(Identifier * l, Node * r) {
			m_left = l;
			m_right = r;
		};

		virtual Node & evaluate(Scope * scope) {

			scope->put(m_left->getName(), &m_right->evaluate(scope));

			return *this;
		};
	private:
		Identifier * m_left;
		bool m_byRef;
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
