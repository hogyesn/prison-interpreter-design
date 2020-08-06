#ifndef PRISON_AST_TYPES_INT
#define PRISON_AST_TYPES_INT

#include <Prison/AST/IExpression.h>

namespace Prison { namespace AST { namespace Types {

class Int : public virtual IExpression {
	public:
		Int() {
			m_type = "int";
			m_size = sizeof(Int);
		}
		Int(int number) {
			m_type = "int";
			m_number = new int(number);
			m_size = sizeof(Int);
		}

		~Int() {};

		int getValue() {
			return *m_number;
		}

		int setValue(int number) {
			m_number = new int(number);

			return *m_number;
		}

		virtual Int & operator+(IExpression & i) {
			Int * newInt = new Int(*m_number);
			const Int * otherInt = dynamic_cast<const Int *>(&i.evaluate());

			*(newInt->m_number) += *(otherInt->m_number);

			return * newInt;
		}

		virtual Int & operator-(IExpression & i) {
			Int * newInt = new Int(*m_number);
			const Int * otherInt = dynamic_cast<const Int *>(&i.evaluate());

			*(newInt->m_number) -= *(otherInt->m_number);

			return * newInt;
		}

		virtual Int & operator-() {
			Int * newInt = new Int(-(*m_number));

			return * newInt;
		};


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
		int * m_number;
};

}}} // namespace Prsion::AST::Types

#endif
