#ifndef PRISON_SCOPE_SYMBOL_ENTRY
#define PRISON_SCOPE_SYMBOL_ENTRY

namespace Prison { namespace Scope {

template <typename T>
class SymbolEntry
{
	public:
		SymbolEntry(const char * key, T value) {
			m_key = key;
			m_value = value;
			m_referenced = 0;
		}

		const char * getKey() {
			return m_key;
		}

		SymbolEntry * get(const char * key) {
			if (strcmp(key, m_key) == 0) {
				if (m_reference) {
					return m_reference;
				}

				return this;
			}

			if (!m_next) {
				return nullptr;
			}

			return m_next->get(key);
		}

		bool unlink(const char * key) {

		}

		SymbolEntry * setNext(SymbolEntry * entry) {
			if (m_next == nullptr) {
				m_next = entry;

				return entry;
			}

			return m_next->setNext(entry);
		}

		SymbolEntry * setReference(SymbolEntry * entry) {
			m_reference = entry;

			entry->increaseReferenced();

			return entry;
		}

		T getValue() {
			return m_value;
		}

		T setValue(T value) {
			m_value = value;

			return m_value;
		}

	private:
		const char * m_key;
		T m_value;
		SymbolEntry * m_next;
		SymbolEntry * m_reference;
		unsigned int m_referenced;

		int increaseReferenced() {
			return ++m_referenced;
		}

		int decreaseReferenced() {
			return --m_referenced;
		}
};

}} // namespace Prison::Scope

#endif
