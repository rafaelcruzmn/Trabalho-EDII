//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//Filipe Mendes O. Rocha - 2020204883

#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    clock_t inicio = clock();
    
    int* arrayP, numeroDeLinhas, numBuckets = 10;
    int comp, troc;

    arrayP = lerArquivo("entrada.txt", &numeroDeLinhas);

    if (strcmp(argv[1], "bolha") == 0) {
        bubbleSort(arrayP, numeroDeLinhas, &comp, &troc);
    } else if (strcmp(argv[1], "insercaodireta") == 0) {
        insercaoDireta(arrayP, numeroDeLinhas, &comp, &troc);
    } else if (strcmp(argv[1], "insercaobinaria") == 0) {
        insercaoBinaria(arrayP, numeroDeLinhas, &comp, &troc);
    } else if (strcmp(argv[1], "shellsort") == 0) {
        shellSort(arrayP, numeroDeLinhas, &comp, &troc);
    } else if (strcmp(argv[1], "selectionsort") == 0) {
        selectionSort(arrayP, numeroDeLinhas, &comp, &troc);
    } else if (strcmp(argv[1], "heapsort") == 0) {
        heapSort(arrayP,numeroDeLinhas, &comp, &troc);
    } else if (strcmp(argv[1], "quicksort") == 0) {
        quickSort(arrayP, 0, numeroDeLinhas - 1,&comp, &troc);
    } else if (strcmp(argv[1], "mergesort") == 0) {
        mergeSort(arrayP, 0, numeroDeLinhas - 1,&comp, &troc);
    } else if (strcmp(argv[1], "radixsort") == 0) {
        radixSort(arrayP, numeroDeLinhas, &troc);
    } else if (strcmp(argv[1], "bucketsort") == 0) {
        bucketSort(arrayP, numeroDeLinhas, numBuckets,&comp, &troc);
    } else {
        printf("Opção inválida.\n");
        free(arrayP);
        return 1;
    }

    printf("Array ordenada: ");
    for (int i = 0; i < numeroDeLinhas; i++) {
        printf("\n%d ", arrayP[i]);
    }
    
    free(arrayP);
    
    clock_t fim = clock();
    double tempoTotal = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %.2f segundos\n", tempoTotal);
    printf("Numero de comparacoes: %d\n", comp);
    printf("Numero de trocas: %d\n", troc);
    return 0;
}
