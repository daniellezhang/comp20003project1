all: main.o bst1.o func.o bst2.o bst.h
	gcc -Wall -o dict1 main.o bst1.o func.o
	gcc -Wall -o dict2 main.o bst2.o func.o

dict1: main.o bst1.o func.o bst.h
	gcc -Wall -o dict1 main.o bst1.o func.o

main.o:bst.h func.c func.o main.c
	gcc -Wall -c -g -o main.o main.c

bst1.o: bst.h dict1.c func.c func.h
	gcc -Wall -c -g -o bst1.o dict1.c

dict2: main.o bst2.o func.o bst.h
	gcc -Wall -o dict2 main.o bst2.o func.o

bst2.o: bst.h dict2.c func.c func.h
	gcc -Wall -c -g -o bst2.o dict2.c

func.o: func.h func.c
	gcc -Wall -c -g -o func.o func.c


clean:
	rm -f *.o dict1 dict2
