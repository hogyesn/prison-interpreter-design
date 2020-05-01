#ifndef PRISON_SCANNER
#define PRISON_SCANNER

#include <fstream>

namespace Prison
{
	class Scanner {

		public:
			Scanner(const char *filename);
			~Scanner();

			char shift();
			char lookahead();
			bool eof();

			unsigned int getLine();
			unsigned int getColumn();
		private:
			std::ifstream m_stream;
			char m_next;
			unsigned int m_current_line;
			unsigned int m_current_column;
			unsigned int m_next_line;
			unsigned int m_next_column;
	};
};

#endif
