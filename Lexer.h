#ifndef PRISON_LEXER
#define PRISON_LEXER

#include "Scanner.h"
#include <map>
#include <iostream>

namespace Prison
{
	struct Token {
		const char * name;
		const char * value;
		unsigned int line;
		unsigned int column;
	};

	class Lexer {
		public:
			Lexer(Scanner * scanner);

			Scanner * getScanner();

			Token shift();
			Token lookahead();
			bool eof();
		private:
			Scanner * m_scanner;
			char * m_next;
			std::map<const char *, const char *> m_tokenRegexes;

			bool regexBroken(const char * s, char lookahead);
			Token createToken(const char * s);
	};
};

#endif
