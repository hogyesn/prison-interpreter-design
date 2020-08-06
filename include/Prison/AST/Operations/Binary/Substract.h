#ifndef PRISON_AST_OPERATIONS_BINARY_SUBSTRACT
#define PRISON_AST_OPERATIONS_BINARY_SUBSTRACT

#include <Prison/AST/IExpression.h>

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class Substract : public virtual IExpression {
	public:
		Substract(IExpression * l, IExpression * r) {
			m_type = "subop";
			m_left = l;
			m_right = r;
		};

		virtual IExpression & evaluate(Scope * scope) {
			return m_left->evaluate(scope) - m_right->evaluate(scope);
		};
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
