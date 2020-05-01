#include "Scanner.h"
#include "Lexer.h"
#include <iostream>
#include <regex>

int main() {

	std::cout << "Prison running\n";

	const char *filename = "test.syntax";

	Prison::Scanner * scanner = new Prison::Scanner(filename);
	Prison::Lexer * lexer = new Prison::Lexer(scanner);
	Prison::Token token;

	while (!lexer->eof())
	{
		token = lexer->shift(); std::cout << token.name << ' ' << token.value << ' ' << token.line << ':' << token.column << '\n';
	}

	delete lexer;

	return 0;
}
