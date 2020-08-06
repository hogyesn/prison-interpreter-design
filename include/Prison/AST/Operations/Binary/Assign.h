#ifndef PRISON_AST_OPERATIONS_BINARY_ASSIGN
#define PRISON_AST_OPERATIONS_BINARY_ASSIGN

#include <Prison/AST/IExpression.h>

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class Assign : public virtual IExpression {
	public:
		Assign(Identifier * l, IExpression * r) {
			m_left = l;
			m_right = r;
			m_byRef = false;
		};

		virtual IExpression & evaluate(Scope * scope) {

			scope->registerEntry(m_left->getName(), &m_right->evaluate(scope));

			return *this;
		};
	private:
		Identifier * m_left;
		bool m_byRef;
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
