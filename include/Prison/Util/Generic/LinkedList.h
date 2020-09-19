#ifndef PRISON_UTL_GEN_LINKED_LIST
#define PRISON_UTL_GEN_LINKED_LIST

namespace Prison { namespace Util { namespace Generic {

template<typename T>
class LinkedList {

	template<typename U>
	class Node {
		public:
			Node(const char * key, U value) {
				m_key = key;
				m_value = value;
				m_next = nullptr;
			}

			~Node()
			{
			}

			const char * getKey() {
				return m_key;
			}

			Node<U> * getNext() {
				return m_next;
			}

			Node<U> * setNext(Node<U> * next) {
				m_next = next;

				return m_next;
			}

			U getValue() {
				return m_value;
			}

			U setValue(U value) {
				m_value = value;

				return m_value;
			}


		private:
			const char * m_key;
			U m_value;
			Node<U> * m_next;
	};

	class NodeAlreadyExistsException {
		public:
			NodeAlreadyExistsException(const char * message) {
				m_message = message;
			}

			const char * getMessage() {
				return m_message;
			}

		private:
			const char * m_message;
	};

	class NodeNotFoundException {
		public:
			NodeNotFoundException(const char * message) {
				m_message = message;
			}

			const char * getMessage() {
				return m_message;
			}

		private:
			const char * m_message;
	};


	public:
		LinkedList() {
			m_count = 0;
			m_head = nullptr;
		}

		~LinkedList() {
			Node<T> * current = m_head;
			Node<T> * next = nullptr;

			while (current != nullptr) {
				next = current->getNext();
				delete current;
				current = next;

				m_count--;
			}

			if (next != nullptr) {
				delete next;
			}
		}

		bool link(const char * key, T value) {
			Node<T> * newItem = new Node<T>(key, value);

			if (!m_head) {
				m_head = newItem;
				m_count++;
				return true;
			}

			Node<T> * tmp = m_head;
			Node<T> * prev = nullptr;

			while (tmp) {
				if (strcmp(tmp->getKey(), key) == 0) {
					delete newItem;

					tmp->setValue(value);

					return true;
				}

				prev = tmp;
				tmp = tmp->getNext();
			}

			prev->setNext(newItem);

			m_count++;

			return true;
		}

		bool unlink(const char * key) {
			Node<T> * prev = nullptr;
			Node<T> * tmp = m_head;

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
			Node<T> * tmp = m_head;

			while (tmp && strcmp(tmp->getKey(), key) != 0) {
				tmp = tmp->getNext();
			}

			if (!tmp) {
				throw new NodeNotFoundException(key);
			}

			return tmp->getValue();
		}

	private:
		int m_count;
		Node<T> * m_head;
};

}}} // namespace Prison::Util::Generic

#endif
