#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void bubbleSort(int vetor[], int size);

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
    printf("\n");

    s = clock();
    bubbleSort(vetor, vectorSize);
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

void bubbleSort(int vetor[], int size) {

    int vetorIdx = 0, vetorIdxB = 0, aux = 0;

    for(vetorIdx=0; vetorIdx<size; vetorIdx++) {
        for(vetorIdxB=0; vetorIdxB<size; vetorIdxB++) {
            if(vetor[vetorIdxB] > vetor[vetorIdxB+1]) {
                aux = vetor[vetorIdxB];
                vetor[vetorIdxB] = vetor[vetorIdxB+1];
                vetor[vetorIdxB+1] = aux;
            }
        }
    }
}
