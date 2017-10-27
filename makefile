all: main.o devRand.o
	gcc main.o devRand.o -o test_07
main.o: main.c devRand.o
	gcc -c main.c
devRand.o: devRand.h
	gcc -c devRand.c

clean:
	rm *.o
	rm test_07

run: all
	./test_07
