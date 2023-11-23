# Spell Checker build file.

CC = g++ -g

all: spellchecker

spellchecker: main.o spellchecker.o
	$(CC) main.o spellchecker.o -o spellchecker

main.o: main.cpp
	$(CC) -c main.cpp

spellchecker.o: spellchecker.cpp
	$(CC) -c spellchecker.cpp

clean:
	rm -f spellchecker main.o spellchecker.o
