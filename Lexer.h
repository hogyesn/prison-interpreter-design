#ifndef PRISON_LEXER
#define PRISON_LEXER

#include "Scanner.h"
#include <map>

namespace Prison
{
	struct Token {
		char * name;
		char * value;
	};

	class Lexer
	{
		public:
			Lexer(Scanner * scanner);

			Scanner * getScanner();

			char * shift();
			char * lookahead();
			bool regexBroken(const char * s, char lookahead);
		private:
			Scanner * m_scanner;
			char * m_next;
			std::map<const char *, const char *> m_tokenRegexes;
	};
};

#endif
