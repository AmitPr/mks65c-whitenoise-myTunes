all: main.o song.o
	gcc -o prog main.c song.o

main.o: main.c song.h
	gcc -c main.c

song.o: song.c song.h
	gcc -c song.c

run: prog
	./prog

clean:
	rm *.o
