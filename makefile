all: main.c
	gcc -o "pipeitup" main.c
run: all
	./pipeitup

