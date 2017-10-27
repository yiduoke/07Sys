all: devRandom.c
	gcc -o homework devRandom.c

clean:
	rm *.o
	rm *~

run: all
	./homework