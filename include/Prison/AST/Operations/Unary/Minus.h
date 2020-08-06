#ifndef PRISON_AST_OPERATIONS_UNARY_MINUS
#define PRISON_AST_OPERATIONS_UNARY_MINUS

#include <Prison/AST/IExpression.h>

namespace Prison { namespace AST { namespace Operations { namespace Unary {

class UnaryMinus : public virtual IExpression {
	public:
		UnaryMinus(IExpression * l) {
			m_left = l;
		};

		virtual IExpression & evaluate(Scope * scope) {
			return -m_left->evaluate(scope);
		};
};

}}}} // namespace Prison::AST::Operations::Unary

#endif
