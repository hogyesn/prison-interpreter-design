#ifndef PRISON_AST_IEXPRESSION
#define PRISON_AST_IEXPRESSION

namespace Prison { namespace AST {

class IExpression
{
	public:
		IExpression() {};
		IExpression(IExpression * l, IExpression * r) {
			m_type = "expression";
			m_left = l;
			m_right = r;
		};

		virtual ~IExpression();

		virtual IExpression & evaluate() {
			if (m_left) {
				m_left->evaluate();
			}

			if (m_right) {
				m_right->evaluate();
			}

			return *this;
		}

		virtual IExpression & evaluate(Scope * scope) {
			if (m_left) {
				m_left->evaluate(scope);
			}

			if (m_right) {
				m_right->evaluate(scope);
			}

			return *this;
		}

		virtual IExpression & operator+(IExpression & expr) {
			return *this;
		};
		virtual IExpression & operator-(IExpression & expr) {
			return *this;
		};
		virtual IExpression & operator-() {
			return *this;
		};
		virtual IExpression & operator=(IExpression & expr) {
			return *this;
		};


		int getSize() {
			return m_size;
		}
	protected:
		const char * m_type;
		int m_size;
		IExpression * m_left;
		IExpression * m_right;
};

}} // namespace Prison:AST

#endif
