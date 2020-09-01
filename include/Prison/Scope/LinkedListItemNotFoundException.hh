#ifndef PRISON_SCOPE_LINKED_LIST_ITEM_NOT_FOUND_EXCEPTION
#define PRISON_SCOPE_LINKED_LIST_ITEM_NOT_FOUND_EXCEPTION

namespace Prison { namespace Scope {

class LinkedListItemNotFoundException {
	public:
		LinkedListItemNotFoundException(const char * message) {
			m_message = message;
		}

		const char * getMessage() {
			return m_message;
		}

	private:
		const char * m_message;
};

}}

#endif
