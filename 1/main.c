//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//

#include "gera.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Inicializa a semente para a função rand() usando o tempo atual
    srand(time(NULL));

    // Gera e imprime 5 números aleatórios entre 0 e 100
    for (int i = 0; i < 5; i++) {
        int numeroAleatorio = rand() % 101; // Gera números entre 0 e 100
        printf("%d\n", numeroAleatorio);
    }

    return 0;
}
