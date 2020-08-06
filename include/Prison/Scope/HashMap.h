#ifndef PRISON_SCOPE_HASHMAP
#define PRISON_SCOPE_HASHMAP

namespace Prison { namespace Scope {

template <typename T>
class HashMap
{
	public:
		HashMap() {
		};

		int put(const char * key, const T entry) {
			unsigned int idx = getIndex(key);

			m_map[idx] = entry;

			return idx;
		}

		T get(const char * key) {
			return m_map[getIndex(key)];
		}

		unsigned int getIndex(const char * key) {
			unsigned int sum = 0;

			int i = 0;
			while (key[i] != '\0') {
				sum += i * key[i];

				i++;
			}

			return sum % m_prime;
		}
	private:
		const static unsigned int m_prime = 1021;
		T m_map[m_prime];
};

}} // namespace Prison::Scope

#endif
