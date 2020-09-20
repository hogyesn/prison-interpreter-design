#ifndef PRISON_AST_TYPES_INT
#define PRISON_AST_TYPES_INT

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Types {

class Int : public virtual Node {
	public:
		Int() {
			m_type = "int";
		}
		Int(int number) {
			m_type = "int";
			m_number = number;
		}

		~Int() {};

		int getValue() {
			return m_number;
		}

		int setValue(int number) {
			m_number = number;

			return m_number;
		}

		virtual Int & operator+(Node & i) {
			Int * newInt = new Int(m_number);
			const Int * otherInt = dynamic_cast<const Int *>(&i.evaluate());

			newInt->m_number += otherInt->m_number;

			return * newInt;
		}

		virtual Int & operator-(Node & i) {
			Int * newInt = new Int(m_number);
			const Int * otherInt = dynamic_cast<const Int *>(&i.evaluate());

			newInt->m_number -= otherInt->m_number;

			return * newInt;
		}

		virtual Int & operator-() {
			Int * newInt = new Int(-m_number);

			return * newInt;
		}

		virtual bool operator==(Node & node) {
			const Int * otherInt = dynamic_cast<const Int *>(&node.evaluate());

			return m_number == otherInt->m_number;
		}
		virtual bool operator!=(Node & node) {
			const Int * otherInt = dynamic_cast<const Int *>(&node.evaluate());

			return m_number == otherInt->m_number;
		}

		virtual bool operator<(Node & node) {
			const Int * otherInt = dynamic_cast<const Int *>(&node.evaluate());

			return m_number < otherInt->m_number;
		}
		virtual bool operator<=(Node & node) {
			const Int * otherInt = dynamic_cast<const Int *>(&node.evaluate());

			return m_number <= otherInt->m_number;
		}

		virtual bool operator>(Node & node) {
			const Int * otherInt = dynamic_cast<const Int *>(&node.evaluate());

			return m_number > otherInt->m_number;
		}
		virtual bool operator>=(Node & node) {
			const Int * otherInt = dynamic_cast<const Int *>(&node.evaluate());

			return m_number >= otherInt->m_number;
		}


		// Int & operator=(Int & i) {
		// 	*this = i;

		// 	return *this;
		// };

		Int & evaluate() {
			return *this;
		};

		Int & evaluate(Scope * scope) {
			return *this;
		};


	private:
		int m_number;
};

}}} // namespace Prsion::AST::Types

#endif
