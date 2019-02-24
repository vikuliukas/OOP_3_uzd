CXX = clang++
CXXFLAGS= -std=c++17 -stdlib=libc++ -Wall -pedantic
CC = clang

all: main.o funkcijos.o
	clang++ main.o funkcijos.o -o main

main.o: main.cpp
	clang++ -c main.cpp

funkcijos.o: funkcijos.cpp
	clang++ -c funkcijos.cpp

test:	all
	./main

clean:
	rm -f *.o main 