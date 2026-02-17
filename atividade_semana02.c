#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Preenche o vetor em ordem decrescente
void preencherVetorDecrescente(int *vetor, int tamanho) {
     int i;
    for (i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

void bubbleSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
    int i, j;

    *comparacoes = 0;
    *movimentacoes = 0;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {

            (*comparacoes)++;

            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;

                (*movimentacoes)++;
            }
        }
    }
}


// Implementação do Selection Sort
void selectionSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
     int i, j;
     
    *comparacoes = 0;
    *movimentacoes = 0;

    for (i = 0; i < tamanho - 1; i++) {

        int menor = i;

        for (j = i + 1; j < tamanho; j++) {

            (*comparacoes)++;

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;

            (*movimentacoes)++;
        }
    }
}

// Função que executa o teste para cada algoritmo
void executarTeste(const char *nomeAlgoritmo,
                   void (*funcaoOrdenacao)(int *, int, int *, int *),
                   int tamanho) {

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    int comparacoes;
    int movimentacoes;

    preencherVetorDecrescente(vetor, tamanho);

    clock_t inicio = clock();
    funcaoOrdenacao(vetor, tamanho, &comparacoes, &movimentacoes);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) * 1000.0 / CLOCKS_PER_SEC;

    printf("| %-14s | %-7d | %-10.3f | %-12d | %-14d |\n",
           nomeAlgoritmo, tamanho, tempo, comparacoes, movimentacoes);

    free(vetor);
}

int main() {

    printf("| Algoritmo      | Tamanho | Tempo (ms) | Comparacoes  | Movimentacoes  |\n");
    printf("|----------------|---------|------------|--------------|----------------|\n");

    executarTeste("Bubble Sort", bubbleSort, 100);
    printf("|----------------|---------|------------|--------------|----------------|\n");

    executarTeste("Selection Sort", selectionSort, 100);
    printf("|----------------|---------|------------|--------------|----------------|\n");

    executarTeste("Bubble Sort", bubbleSort, 1000);
    printf("|----------------|---------|------------|--------------|----------------|\n");

    executarTeste("Selection Sort", selectionSort, 1000);
    printf("|----------------|---------|------------|--------------|----------------|\n");

    executarTeste("Bubble Sort", bubbleSort, 10000);
    printf("|----------------|---------|------------|--------------|----------------|\n");

    executarTeste("Selection Sort", selectionSort, 10000);
    printf("|----------------|---------|------------|--------------|----------------|\n");

    return 0;
}
