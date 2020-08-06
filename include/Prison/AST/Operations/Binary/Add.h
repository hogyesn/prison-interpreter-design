#ifndef PRISON_AST_OPERATIONS_BINARY_ADD
#define PRISON_AST_OPERATIONS_BINARY_ADD

#include <Prison/AST/IExpression.h>

namespace Prison { namespace AST { namespace Operations { namespace Binary {

class Add : public virtual IExpression {
	public:
		Add(IExpression * l, IExpression * r) {
			m_type = "addop";
			m_left = l;
			m_right = r;
		};

		virtual IExpression & evaluate(Scope * scope) {
			return m_left->evaluate(scope) + m_right->evaluate(scope);
		};
};

}}}} // namespace Prison::AST::Operations::Binary

#endif
