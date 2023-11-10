//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//Filipe Mendes O. Rocha - 2020204883

#include "gera.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade = 5;  // Número de elementos a serem gerados
    int limite = 100;    // Valor máximo para os números gerados
    int *numeros = malloc(quantidade * sizeof(int));

    if (numeros == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    int continuar = 1;

    while (continuar) {
        printf("Escolha a opção de geração:\n");
        printf("1 - Aleatórios\n");
        printf("2 - Crescentes\n");
        printf("3 - Decrescentes\n");
        printf("0 - Sair\n");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                gerarNumerosAleatorios(numeros, quantidade, limite);
                break;
            case 2:
                gerarNumerosCrescentes(numeros, quantidade, limite);
                break;
            case 3:
                gerarNumerosDecrescentes(numeros, quantidade, limite);
                break;
            case 0:
                continuar = 0;
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

        if (opcao >= 1 && opcao <= 3) {
            // Imprime os números armazenados
            printf("Números gerados:\n");
            for (int i = 0; i < quantidade; i++) {
                printf("%d\n", numeros[i]);
            }
        }
    }

    // Libera a memória alocada
    free(numeros);

    return 0;
}




