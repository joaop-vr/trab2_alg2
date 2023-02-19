CFLAG= -Wall #-Wshadow                                            
nomePrograma=trab

all: main.o bib_main.o
	gcc $(CFLAG) main.o bib_main.o -o $(nomePrograma)

main.o: main.c
	gcc $(CFLAG) -c main.c

bib_main.o: bib_main.h bib_main.c
	gcc $(CFLAG) -c bib_main.c 

clean:
	rm -f *.o *.gch $(nomePrograma)