CXX = clang++
CXXFLAGS= -std=c++17 -stdlib=libc++ -Wall -pedantic
CC = clang

all: main.o funkcijos.o irasymas.o skaitymas.o
	clang++ main.o funkcijos.o irasymas.o skaitymas.o -o main

main.o: main.cpp
	clang++ -c main.cpp

funkcijos.o: funkcijos.cpp
	clang++ -c funkcijos.cpp

irasymas.o: irasymas.cpp
	clang++ -c irasymas.cpp

skaitymas.o: skaitymas.cpp
	clang++ -c skaitymas.cpp

test:	all
	./main

clean:
	rm -f *.o main vargšiukai.txt šaunuoliai.txt