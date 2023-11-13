all: mainUm mainDois

mainUm: gera.o
	gcc ./Questao1/main.c gera.o -o mainUm

mainDois: ordena.o
	gcc ./Questao2/main.c ordena.o -o mainDois

gera.o: ./Questao1/gera.c ./Questao1/gera.h
	gcc -c ./Questao1/gera.c -o gera.o

ordena.o: ./Questao2/ordena.c ./Questao2/ordena.h
	gcc -c ./Questao2/ordena.c -o ordena.o
