#include "Scanner.h"
#include <iostream>


int main() {

	const char *filename = "test.syntax";

	Prison::Scanner scanner(filename);

	char text[255];
	char c = 0;

	while(!scanner.eof()) {
		// std::cout << scanner.shift();
		text[c] = scanner.shift();
		c++;
	}

	std::cout << text;

	return 0;
}
