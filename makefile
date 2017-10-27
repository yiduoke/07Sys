all: devRandom.o main.o
    gcc -o homework devRandom.o main.o

devRandom.o: devRandom.c devRandom.h 
	gcc -c devRandom.c

main.o: main.c devRandom.h
	gcc -c main.c

clean:
	rm *.o
	rm *~

run: all
	./homework