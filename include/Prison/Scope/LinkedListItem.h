#ifndef PRISON_SCOPE_LINKED_LIST_ITEM
#define PRISON_SCOPE_LINKED_LIST_ITEM

#include "Prison/Scope/LinkedListItemNotFoundException.hh"

namespace Prison { namespace Scope {

template<typename T>
class LinkedListItem {
	public:
		LinkedListItem(const char * key, T value) {
			m_key = key;
			m_value = value;
			m_next = nullptr;
		}

		~LinkedListItem() {
			// delete m_value;
		}

		const char * getKey() {
			return m_key;
		}


		LinkedListItem<T> * getNext() {
			return m_next;
		}

		LinkedListItem<T> * setNext(LinkedListItem<T> * next) {
			m_next = next;

			return m_next;
		}

		T getValue() {
			return m_value;
		}


	private:
		const char * m_key;
		T m_value;
		LinkedListItem<T> * m_next;
};

}} // namespace Prison::Scope

#endif
