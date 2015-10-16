#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quickSort(int vetor[], int first, int last);

int main(void) {

    int vectorSize = 0;
    int i = 0;
    int space  = 20;
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
        if(i == 0) {

        } else if (i%30 == 0) {
            printf("\n");
            printf("                 ");
        }
        if(i == vectorSize-1) {
            printf("%-1i}", vetor[i]);
        } else {
        printf("%-1i, ", vetor[i]);
        }
    }
    printf("\n");

    s = clock();
    quickSort(vetor, 0, vectorSize-1);
    f = clock();

    printf("\n");
    printf("Vetor Ordenado: {");
    for(i=0; i<vectorSize; i++) {
        if(i == 0) {

        } else if (i%30 == 0) {
            printf("\n");
            printf("                  ");
        }
        if(i == vectorSize-1) {
            printf("%-1i}", vetor[i]);
        } else {
        printf("%-1i, ", vetor[i]);
        }

    }

    float t = (f-s)*1000/CLOCKS_PER_SEC;
    printf("\nTempo: %.2f\n", t);

    return 0;
}

void quickSort(int vetor[], int first, int last) {

    int pivot,j,temp,i;

     if(first<last) {
         pivot=first;
         i=first;
         j=last;

         while(i<j) {
             while(vetor[i]<=vetor[pivot]&&i<last)
                 i++;
             while(vetor[j]>vetor[pivot])
                 j--;
             if(i<j){
                 temp=vetor[i];
                  vetor[i]=vetor[j];
                  vetor[j]=temp;
             }
         }

         temp=vetor[pivot];
         vetor[pivot]=vetor[j];
         vetor[j]=temp;
         quickSort(vetor,first,j-1);
         quickSort(vetor,j+1,last);
     }
}
