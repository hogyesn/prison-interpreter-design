#ifndef PRISON_SCANNER
#define PRISON_SCANNER

#include <fstream>

namespace Prison
{
	class Scanner
	{

		public:
			Scanner(const char *filename);

			char shift();
			char lookahead();
			bool eof();
		private:
			std::ifstream m_stream;
			char m_next;
			bool m_eof;
	};
};

#endif
