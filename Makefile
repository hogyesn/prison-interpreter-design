scanner:
	g++ -c Scanner.cpp -o build/Scanner.o

main:
	g++ -c main.cpp -o build/main.o

all: scanner main
	g++ build/*.o -o build/prison

# debug:
# 	g++ -g main.cpp -o temp/a.out


clean:
	rm -rf build
