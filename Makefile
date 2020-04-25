scanner:
	g++ -c Scanner.cpp -o build/Scanner.o

lexer: scanner
	g++ -c Lexer.cpp -o build/Lexer.o

main: lexer
	g++ -c main.cpp -o build/main.o

all: main
	g++ build/*.o -o build/prison

# debug:
# 	g++ -g main.cpp -o temp/a.out


clean:
	rm -rf build
