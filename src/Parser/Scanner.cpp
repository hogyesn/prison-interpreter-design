#include "Prison/Parser/Scanner.h"
#include <fstream>

#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif

using namespace Prison::Parser;

Scanner::Scanner(const char *filename) {
	m_stream.open(filename, std::ifstream::in);

	m_current_line = m_next_line = 1;
	m_current_column = m_next_column = 1;

	m_next = '\0';
	shift();
}

Scanner::~Scanner() {
	m_stream.close();
}

char Scanner::shift() {
	unsigned char current = m_next;
	m_current_line = m_next_line;
	m_current_column = m_next_column;

	while (m_stream.good() && (m_next = m_stream.get())) {
		m_next_column++;

		// windows line ending
		if (m_next == '\r') {
			continue;
		}

		// line ending
		if (m_next == '\n') {
			m_next_line++;
			m_next_column = 1;
		}

		// expressive character found
		if (!isspace(m_next)) {
			break;
		}
	}

	if (eof()) {
		m_stream.close();
	}

	return current;
}

char Scanner::lookahead() {
	return m_next;
}

bool Scanner::eof() {
	return m_stream.eof();
}

unsigned int Scanner::getLine() {
	return m_current_line;
}

unsigned int Scanner::getColumn() {
	return m_current_column;
}
