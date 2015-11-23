#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insertSort(int vetor[], int size);

int main(void) {

    int vectorSize = 0;
    int i = 0;
    clock_t s,f;

    printf("Informe o tamanho do vetor: ");
    scanf("%i", &vectorSize);

    int vetor[vectorSize];

    srand(time(NULL));
    for(i=0; i<vectorSize; i++) {
        vetor[i] = rand()%100;
    }

    printf("\n");
    printf("Vetor Aleatorio: {");
    for(i=0; i<vectorSize; i++) {
        if(i == vectorSize-1) {
            printf("%i}", vetor[i]);
        } else {
        printf("%i, ", vetor[i]);
        }
    }

    s = clock();
    insertSort(vetor, vectorSize);
    f = clock();

    printf("\n");
    printf("Vetor Ordenado: {");
    for(i=0; i<vectorSize; i++) {
        if(i == vectorSize-1) {
            printf("%i}", vetor[i]);
        } else {
        printf("%i, ", vetor[i]);
        }
    }

    float t = (f-s)*1000/CLOCKS_PER_SEC;
    printf("\nTempo: %.2f\n", t);

    return 0;
}

void insertSort(int vetor[], int size) {

    int i = 0, j = 0, value = 0;

    for(i = 1; i < size; i++) {
        value = vetor[i];
        for (j = i - 1; j >= 0 && vetor[j] > value; j--) {
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = value;
    }
}

int buscaBinaria(int vector[], int size, int valor) {
    
}
