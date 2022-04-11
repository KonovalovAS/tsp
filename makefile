start: main.o source.o
	g++ main.o source.o -o start

main.o: main.cpp
	g++ -c main.cpp

source.o: source.cpp head.h
	g++ -c source.cpp

clear:
	rm *.o start
