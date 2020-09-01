#ifndef PRISON_SCOPE_LINKED_LIST
#define PRISON_SCOPE_LINKED_LIST

#include "Prison/Scope/LinkedListItem.h"
#include "Prison/Scope/LinkedListItemNotFoundException.hh"
#include "Prison/Scope/LinkedListItemAlreadyExistsException.hh"

namespace Prison { namespace Scope {

template<typename T>
class LinkedList {
	public:
		LinkedList() {
			m_count = 0;
			m_head = nullptr;
		}

		bool link(const char * key, T value) {
			LinkedListItem<T> * newItem = new LinkedListItem<T>(key, value);

			if (!m_head) {
				m_head = newItem;
				m_count++;
				return true;
			}

			LinkedListItem<T> * tmp = m_head;

			while (tmp->getNext()) {
				if (strcmp(tmp->getKey(), key) == 0) {
					delete newItem;

					throw new Prison::Scope::LinkedListItemAlreadyExistsException(key);
				}

				tmp = tmp->getNext();
			}

			tmp->setNext(newItem);

			m_count++;

			return true;
		}

		bool unlink(const char * key) {
			LinkedListItem<T> * prev = nullptr;
			LinkedListItem<T> * tmp = m_head;

			while (tmp && strcmp(tmp->getKey(), key) != 0) {
				prev = tmp;
				tmp = tmp->getNext();
			}

			if (tmp) {
				if (!prev) {
					m_head = tmp->getNext();
				} else {
					prev->setNext(tmp->getNext());
				}

				delete tmp;

				m_count--;
				return true;
			}

			return false;
		}

		T get(const char * key) {
			LinkedListItem<T> * tmp = m_head;

			while (tmp && strcmp(tmp->getKey(), key) != 0) {
				tmp = tmp->getNext();
			}

			if (!tmp) {
				throw new Prison::Scope::LinkedListItemNotFoundException(key);
			}

			return tmp->getValue();
		}

	private:
		int m_count;
		LinkedListItem<T> * m_head;
};

}} // namespace Prison::Scope

#endif
