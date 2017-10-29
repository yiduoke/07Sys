all: main.o devRandom.c
	gcc -o homework devRandom.o main.o
main.o: main.c devRandom.o
	gcc -c main.c
devRandom.o: devRandom.h
	gcc -c devRandom.c
clean:
	rm -rf *.o
	rm -rf homework
run: all
	./homework

