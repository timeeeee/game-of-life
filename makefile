all: main.o life.o
	g++ -g main.o life.o -o life -lncurses

main.o: main.cpp
	g++ -g -c main.cpp

life.o: life.h life.cpp
	g++ -g -c life.cpp

.PHONY: clean
clean:
	rm -f *.o *~ life
