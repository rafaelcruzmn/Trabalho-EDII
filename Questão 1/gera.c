//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//Filipe Mendes O. Rocha - 2020204883

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
void gerarLista(int *numeros,int quantidade){

    FILE *arquivo;
    const char *nomeArquivo = "entrada.txt";

    // Abre o arquivo para escrita
    arquivo = fopen(nomeArquivo, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s para escrita.\n", nomeArquivo);
        return;
    }

    // Escreve cada elemento da lista no arquivo
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d\n", numeros[i]);
    }

    fclose(arquivo);

    printf("Lista salva com sucesso no arquivo %s.\n", nomeArquivo);

 }