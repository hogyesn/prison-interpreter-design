#ifndef PRISON_AST_IDENTIFIER
#define PRISON_AST_IDENTIFIER

#include "Prison/AST/IExpression.h"

namespace Prison { namespace AST {

class Identifier : public virtual IExpression {
	public:
		Identifier(const char * name) {
			m_name = name;
		};

		const char * getName() {
			return m_name;
		}

		IExpression & evaluate(Scope * scope) {
			return *(scope->getEntry(m_name));
		};
	private:
		const char * m_name;
};

}} // namespace Prison:AST

#endif
