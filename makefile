flashcard: main.o card.o word.o node.o
	gcc -o flashcard main.o card.o word.o node.o

main.o: main.c card.h word.h node.h
	gcc -c main.c

card.o: card.c card.h
	gcc -c card.c

word.o: word.c word.h node.h
	gcc -c word.c

node.o: node.c node.h
	gcc -c node.c
