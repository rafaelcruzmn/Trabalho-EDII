//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//Filipe Mendes O. Rocha - 2020204883

#include "gera.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// responsavel pelo tempo
#include <time.h>

int main(int argc, char *argv[]) {

    //inicio da contagem
    clock_t inicio = clock();

    if (argc != 3) {
        printf("Uso: %s -a|-c|-d n\n", argv[0]);
        return 1;
    }

    int quantidade = atoi(argv[2]);
    int limite = 300000;  // Valor máximo para os números gerados
    int *numeros = malloc(quantidade * sizeof(int));

    if (numeros == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    if (strcmp(argv[1], "-a") == 0) {
        gerarNumerosAleatorios(numeros, quantidade, limite);
    } else if (strcmp(argv[1], "-c") == 0) {
        gerarNumerosCrescentes(numeros, quantidade, limite);
    } else if (strcmp(argv[1], "-d") == 0) {
        gerarNumerosDecrescentes(numeros, quantidade, limite);
    } else {
        printf("Opção inválida.\n");
        free(numeros);
        return 1;
    }

    // Imprime os números gerados
    printf("Numeros gerados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d\n", numeros[i]);
    }

    gerarLista(numeros, quantidade);

    // Libera a memória alocada
    free(numeros);

    //fim da contagem
    clock_t fim = clock();
    //calcula o tempo
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.2f segundos\n", tempoTotal);


    return 0;
}

