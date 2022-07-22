#include "Prison/Parser/Lexer.h"
#include "Prison/Parser/Scanner.h"
#include "Prison/Parser/Grammar.h"
#include <ctype.h>
#include <regex>
#include <map>
#include <iostream>

using namespace Prison::Parser;

Lexer::Lexer(Scanner * scanner, Grammar * grammar) {
	m_scanner = scanner;


	m_tokenRegexes["nl"] = "\r?\n";
	m_tokenRegexes["utf8bom"] = "\xef?\xbb?\xbf?";

	m_tokenRegexes["if"] = "if";
	m_tokenRegexes["else"] = "else";
	m_tokenRegexes["for"] = "for";
	m_tokenRegexes["return"] = "return";

	m_tokenRegexes["id"] = "[a-zA-Z][a-zA-Z_0-9]*";

	m_tokenRegexes["int"] = "[0-9]+";
	m_tokenRegexes["float"] = "([0-9]+([.][0-9]*)?|[.][0-9]+)";
	m_tokenRegexes["false"] = "false";
	m_tokenRegexes["true"] = "true";
	m_tokenRegexes["string"] = "\".*\"";

	m_tokenRegexes["plus"] = "\\+";
	m_tokenRegexes["semicolon"] = "\\;";
	m_tokenRegexes["ro_br_l"] = "\\(";
	m_tokenRegexes["ro_br_r"] = "\\)";
	m_tokenRegexes["sq_br_l"] = "\\[";
	m_tokenRegexes["sq_br_r"] = "\\]";
	m_tokenRegexes["cu_br_l"] = "\\{";
	m_tokenRegexes["cu_br_r"] = "\\}";
	m_tokenRegexes["assign"] = "=";
	m_tokenRegexes["equals"] = "==";
	m_tokenRegexes["not_equals"] = "!=";

	m_next = new char[0];
	shift();
}

Lexer::~Lexer() {
	delete m_next;
	delete m_scanner;
}

Scanner * Lexer::getScanner() {
	return m_scanner;
}

Token Lexer::shift() {
	char * current = new char[strlen(m_next)];
	strcpy(current, m_next);

	char * parseStack = new char[255];
	char nextChar;
	unsigned char c = 0;

	unsigned int line = m_scanner->getLine();
	unsigned int column = m_scanner->getColumn();

	while (!eof() && (nextChar = m_scanner->shift())) {
		parseStack[c] = nextChar;
		parseStack[++c] = '\0';

		if (regexBroken(parseStack, m_scanner->lookahead())) {
			break;
		}
	}

	delete[] m_next;
	m_next = new char[c];
	strcpy(m_next, parseStack);

	delete[] parseStack;

	Token token = createToken(current);

	delete[] current;

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

bool Lexer::regexBroken(const char * s, const char lookahead) {
	int size = strlen(s);
	char * token = new char[256];


	strcpy(token, s);

	token[size] = lookahead;
	token[size + 1] = '\0';
}

// bool regexBrokenBak(const char * s, const char lookahead) {
// 	int size = strlen(s);
// 	char * token = new char[256];


// 	strcpy(token, s);

// 	token[size] = lookahead;
// 	token[size + 1] = '\0';

// 	std::map<const char *, const char *>::iterator it;


// 	for (it = m_tokenRegexes.begin(); it != m_tokenRegexes.end(); it++) {
// 		std::regex regex(it->second);

// 		if (std::regex_match(token, regex)) {
// 			delete[] token;
// 			return false;
// 		}
// 	}

// 	delete[] token;

// 	return true;
// }

Token Lexer::createToken(const char * s) {
	std::map<const char *, const char *>::iterator it;

	Token token;

	token.name = "unrecognized";
	token.value = s;

	for (it = m_tokenRegexes.begin(); it != m_tokenRegexes.end(); it++) {
		std::regex regex(it->second);

		if (std::regex_match(s, regex)) {
			token.name = it->first;

			return token;
		}
	}

	return token;
}
