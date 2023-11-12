//Trabalho de:
//Rafael Cruz M. Nunes - 2020204249
//Filipe Mendes O. Rocha - 2020204883

#ifndef ARQUIVO_FUNCOES_H
#define ARQUIVO_FUNCOES_H

// Estrutura para representar um bucket (compartimento)
typedef struct Bucket {
    int tamanho;
    int *itens;
} Bucket;
typedef struct {
    int comparacoes;
    int trocas;
} Estatisticas;

int* lerArquivo(const char* nomeArquivo, int* numeroDeLinhas);
void bubbleSort(int *array, int tamanho, int *comp, int *troc);
void imprimirArray(int *array, int tamanho);
void escreverResultado(const char* nomeArquivo, int* array, int tamanho);
void insercaoBinaria(int *array, int tamanho, int *comp, int *troc);
int buscaBinaria(int *array, int inicio, int fim, int chave, int* comp);
void insercaoDireta(int *array, int tamanho,int *comp, int *troc);
void shellSort(int *array, int tamanho, int *comp, int *troc);
void selectionSort(int *array, int tamanho, int *comp, int *troc);
void heapify(int *array, int tamanho, int indice, int *comp, int *troc);
void heapSort(int *array, int tamanho, int *comp, int *troc);
int particionar(int *array, int baixo, int alto,int *comp, int *troc);
void quickSort(int *array, int baixo, int alto,int *comp, int *troc);
void merge(int *array, int esquerda, int meio, int direita, int *comp, int *troc);
void mergeSort(int *array, int esquerda, int direita, int *comp, int *troc);
void radixSort(int *array, int tamanho, int *troc);
void ordenarBucket(Bucket *bucket);
void bucketSort(int *array, int tamanho, int numBuckets,int *comp, int *troc);



#endif
