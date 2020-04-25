#include "Lexer.h"
#include <ctype.h>
#include <regex>
#include <map>
#include <iostream>

using namespace Prison;

Lexer::Lexer(Scanner * scanner) {
	m_scanner = scanner;

	m_tokenRegexes["string"] = "[a-zA-Z][a-zA-Z_0-9]*";
	m_tokenRegexes["int"] = "[0-9]+";
	m_tokenRegexes["plus"] = "\\+";
	m_tokenRegexes["semicolon"] = "\\;";
	m_tokenRegexes["equals"] = "=";

	m_next = new char[0];
	shift();
}

Scanner * Lexer::getScanner() {
	return m_scanner;
}

Token Lexer::shift() {
	char * current = new char[strlen(m_next)];
	strcpy(current, m_next);

	char * parseStack = new char[255];
	char nextChar;
	char c = 0;

	unsigned int line = m_scanner->getLine();
	unsigned int column = m_scanner->getColumn();

	while (!eof() && (nextChar = m_scanner->shift())) {
		parseStack[c] = nextChar;
		c++;

		if (regexBroken(parseStack, m_scanner->lookahead())) {
			break;
		}
	}

	delete m_next;
	m_next = new char[c];
	strcpy(m_next, parseStack);

	Token token = createToken(current);

	token.line = line;
	token.column = column;

	return token;
}

Token Lexer::lookahead() {
	return createToken(m_next);
}

bool Lexer::eof() {
	return m_scanner->eof();
}

bool Lexer::regexBroken(const char * s, char lookahead) {
	int size = strlen(s);
	char * token = new char[size + 1];

	strcpy(token, s);

	token[size] = lookahead;

	std::map<const char *, const char *>::iterator it;

	for (it = m_tokenRegexes.begin(); it != m_tokenRegexes.end(); it++) {
		std::regex regex(it->second);

		if (std::regex_match(token, regex)) {
			return false;
		}

	}

	return true;
}

Token Lexer::createToken(const char * s) {
	std::map<const char *, const char *>::iterator it;

	Token token;

	token.name = "unrecognized";
	token.value = "";

	for (it = m_tokenRegexes.begin(); it != m_tokenRegexes.end(); it++) {
		std::regex regex(it->second);

		if (std::regex_match(s, regex)) {
			token.name = it->first;
			token.value = s;


			return token;
		}
	}

	return token;
}
