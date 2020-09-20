#ifndef PRISON_AST_STMNT_IF
#define PRISON_AST_STMNT_IF

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

#include "Prison/AST/Types/Bool.h"

#include "Prison/AST/Statements/Sequence.h"

using namespace Prison::AST::Types;

namespace Prison { namespace AST { namespace Statements {

class If : public virtual Node {
	public:
		If(Bool * condition, Sequence * then, Sequence * _else = nullptr) {
			m_condition = condition;
			m_then = then;
			m_else = _else;
		}

		virtual Sequence & evaluate(Scope * scope) {
			if (m_condition->getValue()) {
				return m_then->evaluate(scope);
			} else {
				return m_else->evaluate(scope);
			}
		}
	private:
		Bool * m_condition;
		Sequence * m_then;
		Sequence * m_else;

};

}}};

#endif
