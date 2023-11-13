//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//Filipe Mendes O. Rocha - 2020204883

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordena.h"
#define MAX_LINE_LENGTH 500000



void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *array, int tamanho, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*comp)++;
            if (array[j] > array[j + 1]) {
                trocar(&array[j], &array[j + 1]);
                (*troc)++;
            }
        }
    }
    escreverResultado("saida.txt", array, tamanho);
}

int* lerArquivo(const char* nomeArquivo, int* numeroDeLinhas) {
    FILE* arquivo;
    char linha[MAX_LINE_LENGTH];
    int* array;

    // Abre o arquivo em modo de leitura
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Conta o número de linhas no arquivo
    *numeroDeLinhas = 0;
    while (fgets(linha, MAX_LINE_LENGTH, arquivo) != NULL) {
        (*numeroDeLinhas)++;
    }

    // Volta para o início do arquivo
    rewind(arquivo);

    // Aloca o array dinamicamente
    array = (int*)malloc(*numeroDeLinhas * sizeof(int));

    // Lê cada linha do arquivo e armazena no array
    for (int i = 0; i < *numeroDeLinhas; i++) {
        fscanf(arquivo, "%d", &array[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return array;
}

void escreverResultado(const char* nomeArquivo, int* array, int tamanho) {
    FILE* arquivo;

    // Abre o arquivo em modo de escrita
    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    // Escreve o array ordenado no arquivo
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", array[i]);
    }
    // Fecha o arquivo
    fclose(arquivo);
}

void imprimirArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insercaoDireta(int *array, int tamanho,int *comp, int *troc) {
    int i, chave, j;
    *comp = 0;
    *troc = 0;
    for (i = 1; i < tamanho; i++) {
        chave = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j = j - 1;
            (*troc)++;
            (*comp)++;
        }
        array[j + 1] = chave;
        (*troc)++;
    }
    escreverResultado("saida.txt", array, tamanho);
}

void insercaoBinaria(int *array, int tamanho, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = array[i];
        j = i - 1;

        // Encontra a posição correta para a chave usando busca binária
        int posicao = buscaBinaria(array, 0, j, chave, comp);

        // Move os elementos maiores para a direita
        while (j >= posicao) {
            array[j + 1] = array[j];
            j = j - 1;
            (*troc)++;
        }

        // Insere a chave na posição correta
        array[j + 1] = chave;
    }
    escreverResultado("saida.txt", array, tamanho);
}

//função usada pela inserçãoBinaria
int buscaBinaria(int *array, int inicio, int fim, int chave, int* comp) {
    if (fim <= inicio) {
        (*comp)++;
        return (chave > array[inicio]) ? (inicio + 1) : inicio;
    }

    int meio = (inicio + fim) / 2;

    if (chave == array[meio]) {
        (*comp)++;
        return meio + 1;
    }

    (*comp)++;
    if (chave > array[meio]) {
        return buscaBinaria(array, meio + 1, fim, chave, comp);
    }
    return buscaBinaria(array, inicio, meio - 1, chave, comp);
}

void shellSort(int *array, int tamanho, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < tamanho; i++) {
            int chave = array[i];
            int j = i;

            while (j >= intervalo && array[j - intervalo] > chave) {
                array[j] = array[j - intervalo];
                j -= intervalo;
                (*comp)++; (*troc)++;
            }

            array[j] = chave;
            (*troc)++;
        }
    }
    escreverResultado("saida.txt", array, tamanho);
}

void selectionSort(int *array, int tamanho, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;

        // Encontra o índice do menor elemento
        for (int j = i + 1; j < tamanho; j++) {
            (*comp)++;  // Incrementa o contador de comparações
            if (array[j] < array[indiceMenor]) {
                indiceMenor = j;
            }
        }

        // Troca os elementos
        if (indiceMenor != i) {
            int temp = array[i];
            array[i] = array[indiceMenor];
            array[indiceMenor] = temp;
            (*troc)++;     
        }
    }


    escreverResultado("saida.txt", array, tamanho);
}

// Função usada pelo heapSort
void heapify(int *array, int tamanho, int indice, int *comp, int *troc) {
    int maior = indice;
    int filhoEsquerdo = 2 * indice + 1;
    int filhoDireito = 2 * indice + 2;

    if (filhoEsquerdo < tamanho) {
        (*comp)++;
        if (array[filhoEsquerdo] > array[maior]) {
            maior = filhoEsquerdo;
        }
    }

    if (filhoDireito < tamanho) {
        (*comp)++;
        if (array[filhoDireito] > array[maior]) {
            maior = filhoDireito;
        }
    }

    if (maior != indice) {
        // Troca os elementos e chama recursivamente heapify
        (*troc)++;
        int temp = array[indice];
        array[indice] = array[maior];
        array[maior] = temp;
        heapify(array, tamanho, maior, comp, troc);
    }
}

void heapSort(int *array, int tamanho, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;

    // Constrói a heap (rearranja o array)
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(array, tamanho, i, comp, troc);
    }

    // Extrai elementos um por um da heap
    for (int i = tamanho - 1; i > 0; i--) {
        // Move a raiz atual para o final
        (*troc)++;
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Chama max heapify na heap reduzida
        heapify(array, i, 0, comp, troc);
    }

    escreverResultado("saida.txt", array, tamanho);
}


//Função usada pelo quicksort
int particionar(int *array, int baixo, int alto,int *comp, int *troc) {
    *comp = 0;
    *troc = 0;
    int pivo = array[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        (*comp)++;
        if (array[j] <= pivo) {
            i++;
            trocar(&array[i], &array[j]);
            (*troc)++;
        }
    }

    trocar(&array[i + 1], &array[alto]);
    (*troc)++;
    return (i + 1);
}

void quickSort(int *array, int baixo, int alto,int *comp, int *troc) {
    *comp = 0;
    *troc = 0;
    int tamanho = alto + 1;
    if (baixo < alto) {
        // Encontra o índice do elemento que será o pivo
        int indicePivo = particionar(array, baixo, alto,comp,troc);

        // Recursivamente ordena os elementos antes e depois do pivo
        quickSort(array, baixo, indicePivo - 1,comp,troc);
        quickSort(array, indicePivo + 1, alto,comp,troc);
    }
    escreverResultado("saida.txt", array, tamanho);
}
//Função usada pelo mergeSort
void merge(int *array, int esquerda, int meio, int direita, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria arrays temporários
    int *esq = (int *)malloc(n1 * sizeof(int));
    int *dir = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os arrays temporários
    for (i = 0; i < n1; i++) {
        esq[i] = array[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        dir[j] = array[meio + 1 + j];
    }

    // Combina os arrays temporários de volta ao array original
    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        (*comp)++;
        if (esq[i] <= dir[j]) {
            array[k] = esq[i];
            i++;
        } else {
            array[k] = dir[j];
            j++;
        }
        k++;
        (*troc)++;
    }

    // Copia os elementos restantes de esq[], se houver algum
    while (i < n1) {
        array[k] = esq[i];
        i++;
        k++;
        (*troc)++;
    }

    // Copia os elementos restantes de dir[], se houver algum
    while (j < n2) {
        array[k] = dir[j];
        j++;
        k++;
        (*troc)++;
    }

    // Libera os arrays temporários
    free(esq);
    free(dir);
}

void mergeSort(int *array, int esquerda, int direita, int *comp, int *troc) {
    *comp = 0;
    *troc = 0;
    int tamanho = direita + 1;
    if (esquerda < direita) {
        // Encontra o ponto médio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(array, esquerda, meio,comp,troc);
        mergeSort(array, meio + 1, direita,comp,troc);

        // Combina as metades ordenadas
        merge(array, esquerda, meio, direita,comp, troc);
    }
    escreverResultado("saida.txt", array, tamanho);
}
//Função usada pelo radixSort
int encontrarMaior(int *array, int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

void radixSort(int *array, int tamanho, int *troc) {
    *troc = 0;
    int maior = encontrarMaior(array, tamanho);
    int exp;
    
    // Loop através de cada dígito
    for (exp = 1; maior / exp > 0; exp *= 10) {
        int output[tamanho];
        int i;
        int count[10] = {0};
        
        // Conta a ocorrência de cada dígito
        for (i = 0; i < tamanho; i++) {
            count[(array[i] / exp) % 10]++;
        }
        
        // Atualiza count[i] para armazenar a posição real do próximo índice do dígito
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Constrói o array de saída
        for (i = tamanho - 1; i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
            (*troc)++;
        }
        
        // Copia o array de saída de volta para o array original
        for (i = 0; i < tamanho; i++) {
            array[i] = output[i];
        }
    }
    printf("Trocas: %d\n", troc);
    escreverResultado("saida.txt", array, tamanho);
}

// Função usada para qsort
static int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para ordenar um bucket
void ordenarBucket(Bucket *bucket) {
    qsort(bucket->itens, bucket->tamanho, sizeof(int), comparar);
}

void bucketSort(int *array, int tamanho, int numBuckets,int *comp, int *troc){
    *comp = 0;
    *troc = 0;
    // Encontrar o valor máximo no array
    int valorMaximo = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > valorMaximo) {
            valorMaximo = array[i];
        }
    }

    // Inicializa os buckets
    Bucket *buckets = (Bucket *)malloc(numBuckets * sizeof(Bucket));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].tamanho = 0;
        buckets[i].itens = NULL;
    }

    // Distribui os elementos nos buckets
    for (int i = 0; i < tamanho; i++) {
        int indiceBucket = (array[i] * numBuckets) / (valorMaximo + 1);

        // Aumenta o tamanho do bucket
        buckets[indiceBucket].tamanho++;

        // Realoca o array de itens do bucket
        buckets[indiceBucket].itens = (int *)realloc(buckets[indiceBucket].itens, buckets[indiceBucket].tamanho * sizeof(int));

        // Adiciona o elemento ao bucket
        buckets[indiceBucket].itens[buckets[indiceBucket].tamanho - 1] = array[i];
    }

    // Ordena cada bucket
    for (int i = 0; i < numBuckets; i++) {
        (*comp)++;
        ordenarBucket(&buckets[i]);
    }

    // Concatena os buckets ordenados para obter o array final
    int indiceArray = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].tamanho; j++) {
            array[indiceArray++] = buckets[i].itens[j];
            (*troc)++;
        }
        // Libera a memória alocada para os itens do bucket
        free(buckets[i].itens);
    }
    escreverResultado("saida.txt", array, tamanho);
    // Libera a memória alocada para os buckets
    free(buckets);
}