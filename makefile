all : main.o song.o library.o
	gcc -o prog main.c song.o library.o

main.o: main.c song.h library.h
	gcc -c main.c

song.o: song.c song.h
	gcc -c song.c

library.o: library.c library.h
	gcc -c library.c

run : prog
	./prog

clean:
	rm *.o
	rm prog