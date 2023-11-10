//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//
#include "gera.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarNumerosAleatorios(int *numeros, int quantidade, int limite) {
    srand(time(NULL));

    for (int i = 0; i < quantidade; i++) {
        numeros[i] = rand() % limite;
    }
}

void gerarNumerosCrescentes(int *numeros, int quantidade, int limite) {
    srand(time(NULL));

    numeros[0] = rand() % (limite / quantidade);

    for (int i = 1; i < quantidade; i++) {
        numeros[i] = numeros[i - 1] + rand() % (limite / quantidade);
    }
}

void gerarNumerosDecrescentes(int *numeros, int quantidade, int limite) {
    srand(time(NULL));

    numeros[0] = limite - rand() % (limite / quantidade);

    for (int i = 1; i < quantidade; i++) {
        numeros[i] = numeros[i - 1] - rand() % (limite / quantidade);
    }
}




