#ifndef PRISON_AST_IEXPRESSION
#define PRISON_AST_IEXPRESSION

#include "Prison/AST/Scope.h"
// #include "Prison/AST/Types/Bool.h"

namespace Prison { namespace AST {

using namespace Prison::AST;

class Scope;

class Node
{
	public:
		Node() {};
		Node(Node * l, Node * r) {
			m_type = "node";
			m_left = l;
			m_right = r;
		};

		virtual ~Node() {}

		virtual Node & evaluate() {
			if (m_left) {
				m_left->evaluate();
			}

			if (m_right) {
				m_right->evaluate();
			}

			return *this;
		}

		virtual Node & evaluate(Scope * scope) {
			if (m_left) {
				m_left->evaluate(scope);
			}

			if (m_right) {
				m_right->evaluate(scope);
			}

			return *this;
		}

		virtual Node & operator+(Node & node) {
			return *this;
		};
		virtual Node & operator-(Node & node) {
			return *this;
		};
		virtual Node & operator-() {
			return *this;
		};
		virtual Node & operator=(Node & node) {
			return *this;
		};
		virtual bool operator==(Node & node) {
			return *this == node;
		};
		virtual bool operator!=(Node & node) {
			return *this != node;
		};
		virtual bool operator<(Node & node) {
			return *this < node;
		};
		virtual bool operator<=(Node & node) {
			return *this <= node;
		};
		virtual bool operator>(Node & node) {
			return *this > node;
		};
		virtual bool operator>=(Node & node) {
			return *this >= node;
		};
		virtual bool operator!() {
			return !*this;
		};
	protected:
		const char * m_type;
		Node * m_left;
		Node * m_right;
};

}} // namespace Prison:AST

#endif
