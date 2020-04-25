#include "Scanner.h"
#include <fstream>

using namespace Prison;

Scanner::Scanner(const char *filename)
{
	m_stream.open(filename, std::ifstream::in);
	m_next = m_stream.get();
	m_eof = false;
}

Scanner::~Scanner()
{
	m_stream.close();
}

char Scanner::shift()
{
	char current = m_next;

	while (m_stream.good() && isspace(m_next = m_stream.get())) {}

	if (!m_stream.good()) {
		m_eof = true;
		m_stream.close();
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
