all:
	gcc -Wall -o unit_test unit_test.c wordSort.c
	./unit_test
