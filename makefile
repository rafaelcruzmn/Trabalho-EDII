CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: gera ordena

gera: gera.c
	$(CC) $(CFLAGS) gera.c -o gera

ordena: ordena.c
	$(CC) $(CFLAGS) ordena.c -o ordena

clean:
	rm -f gera ordena
