#ifndef PRISON_AST_IDENTIFIER
#define PRISON_AST_IDENTIFIER

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

using Prison::AST::Scope;

namespace Prison { namespace AST {

class Identifier : public virtual Node {
	public:
		Identifier(const char * name) {
			m_name = name;
		};

		const char * getName() {
			return m_name;
		}

		Node & evaluate(Scope * scope) {
			return *(scope->get(m_name));
		};
	private:
		const char * m_name;
};

}} // namespace Prison:AST

#endif
