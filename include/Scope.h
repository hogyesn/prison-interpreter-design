#ifndef PRISON_SCOPE
#define PRISON_SCOPE

#include <map>

namespace Prison
{
	class IExpression
	{
		public:
			IExpression(){};
			virtual ~IExpression();

			virtual IExpression & execute() = 0;

			int getSize() {
				return m_size;
			}
		protected:
			int m_size;
	};

	IExpression::~IExpression() {

	};

	template <class T> class ValueEntry: public virtual IExpression {
		public:
			ValueEntry (T value) {
				m_value = value;
				m_size = sizeof(value);
			}

			T setValue(T value) {
				m_value = value;
			}

			T getValue() {
				return m_value;
			}

			T * getAddress() {
				return &m_value;
			};

			virtual IExpression & execute () {
				return *this;
			}

			// char * getType() {
			// 	return typeid(T);
			// };
		private:
			T m_value;
	};

	class Scope;

	class Assign : public virtual IExpression {
		public:
			Assign(Scope * scope, const char * identifier, IExpression * expression) {
				m_scope = scope;
				m_identifier = identifier;
				m_expression = expression;
			}

			virtual IExpression & execute();
		private:
			Scope * m_scope;
			const char * m_identifier;
			IExpression * m_expression;
	};



	class Scope {

		public:
			Scope() {};
			~Scope();

			template<class T> IExpression * registerEntry(const char * identifier, const T value) {
				ValueEntry<T> * entry = new ValueEntry<T>(value);

				m_register[identifier] = entry;

				return entry;
			}

			IExpression * getEntry(const char * identifier) {
				return m_register[identifier];
			}

		private:
			std::map<const char *, IExpression *> m_register;

	};

	IExpression & Assign::execute() {
		ValueEntry<int> resultInt = dynamic_cast<ValueEntry<int> &>(m_expression->execute());

		m_scope->registerEntry(m_identifier, resultInt.getValue());

		return *this;
	};
};

#endif
