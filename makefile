main : main.c
	gcc -o prog main.c
run : prog
	./prog