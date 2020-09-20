#ifndef PRISON_AST_STMNT_SEQ
#define PRISON_AST_STMNT_SEQ

#include "Prison/AST/Node.h"
#include "Prison/AST/Scope.h"

namespace Prison { namespace AST { namespace Statements {

class Sequence : public virtual Node {
	public:
		Sequence() {
			// TODO queue
			// m_commands = new Queue<Node *>();
			m_count = 0;
		}

		~Sequence() {
			// delete[] m_commands;
		}

		void append(Node * node) {
			m_commands[m_count++] = node;
		}

		virtual Sequence & evaluate(Scope * scope) {
			for (int i = 0; i < m_count; i++)
			{
				m_commands[i]->evaluate(scope);
			}

			return *this;
		}


	private:
		Node * m_commands[10];
		int m_count;
};

}}};

#endif
