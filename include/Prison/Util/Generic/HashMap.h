#ifndef PRISON_UTL_GEN_HASHMAP
#define PRISON_UTL_GEN_HASHMAP

#include "Prison/Util/Generic/LinkedList.h"

using namespace Prison::Util::Generic;

namespace Prison { namespace Util { namespace Generic {

template <typename T>
class HashMap
{
	public:
		HashMap() {
			for (unsigned int i = 0; i < m_prime; i++)
			{
				m_map[i] = new LinkedList<T>();
			}
		};

		~HashMap() {
			for (unsigned int i = 0; i < m_prime; i++)
			{
				delete m_map[i];
			}
		}

		bool put(const char * key, const T value) {
			unsigned int idx = getIndex(key);

			m_last_index = idx;

			LinkedList<T> * ll = m_map[idx];

			return ll->link(key, value);
		}

		T get(const char * key) {
			unsigned int idx = getIndex(key);

			LinkedList<T> * ll = m_map[idx];

			return ll->get(key);
		}

		bool unlink(const char * key) {
			unsigned int idx = getIndex(key);

			LinkedList<T> * ll = m_map[idx];

			return ll->unlink(key);
		}
	private:
		const static unsigned int m_prime = 1021;
		LinkedList<T> * m_map[m_prime];
		int m_last_index;

		unsigned int getIndex(const char * key) {
			unsigned int sum = 0;

			int i = 0;
			while (key[i] != '\0') {
				sum += i * key[i];

				i++;
			}

			return sum % m_prime;
		}
};

}}} // namespace Prison::Util::Generic

#endif
