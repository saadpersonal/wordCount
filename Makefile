all:
	gcc -Wall -o wordCount test.c wordSort.c
	./wordCount
