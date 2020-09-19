#ifndef PRISON_AST_SCOPE
#define PRISON_AST_SCOPE

#include "Prison/AST/Node.h"
#include "Prison/Util/Generic/HashMap.h"

namespace Prison { namespace AST {

using namespace Prison::AST;

class Node;

class Scope {
	public:
		Scope(HashMap<Node *> * map) {
			m_map = map;
		}

		~Scope() {
			delete m_map;
		}

		Node * get(const char * key) {
			return m_map->get(key);
		}

		bool put(const char * key, Node * node) {
			return m_map->put(key, node);
		}
	private:
		HashMap<Node *> * m_map;
};

}}; // namespace Prison::AST

#endif
