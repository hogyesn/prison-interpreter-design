#ifndef PRISON_PARSER_LEXER
#define PRISON_PARSER_LEXER

#include "Scanner.h"
#include "Grammar.h"
#include <map>
#include <iostream>

namespace Prison { namespace Parser {

struct Token {
	const char * name;
	const char * value;
	unsigned int line;
	unsigned int column;
};

class Lexer {
	public:
		Lexer(Scanner * scanner, Grammar * grammar);
		~Lexer();

		Scanner * getScanner();

		Token shift();
		Token lookahead();
		bool eof();
	private:
		Scanner * m_scanner;
		Grammar * m_grammar;
		char * m_next;
		std::map<const char *, const char *> m_tokenRegexes;

		bool regexBroken(const char * s, const char lookahead);
		Token createToken(const char * s);
};

}} // namespace Prison::Parser

#endif
