#ifndef PRISON_AST_TYPES_BOOL
#define PRISON_AST_TYPES_BOOL

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Types {

class Bool : public virtual Node {
	public:
		Bool() {
			m_type = "bool";
		}

		Bool(bool value) {
			m_value = value;
		}

		bool getValue() {
			return m_value;
		}

		virtual Bool & evaluate() {
			return *this;
		}

		virtual Bool & evaluate(Scope * scope) {
			return *this;
		}

	private:
		bool m_value;
};

}}} // namespace Prsion::AST::Types

#endif
