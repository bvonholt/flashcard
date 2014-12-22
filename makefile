flashcard: main.o card.o word.o
	gcc -o flashcard main.o card.o word.o

main.o: main.c card.h word.h
	gcc -c main.c

card.o: card.c card.h
	gcc -c card.c

word.0: word.c word.h
	gcc -c word.c
