#include "Scanner.h"
#include <fstream>

using namespace Prison;

Scanner::Scanner(const char *filename)
{
	m_stream.open(filename, std::ifstream::in);
	m_next = m_stream.get();
	m_eof = false;
}

char Scanner::shift()
{
	char current = m_next;

	if (m_stream.good()) {
		m_next = m_stream.get();
	} else {
		m_eof = true;
		m_stream.close();
		return '\0';
	}

	return current;
}

char Scanner::lookahead()
{
	return m_next;
}

bool Scanner::eof()
{
	return m_eof;
}
