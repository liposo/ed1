/*
 Aluno: Felipe Zanella Bourscheid
 Compilador: GCC
 
 */

#include <stdio.h>
#include <stdlib.h>

float calculaMedia(int *vetor, int qtLidos);

int main(void) {

	int qtValores = 0;
        int qtLido = 0;
        int qtMaiorQueMedia = 0;
	int qtMenorQueMedia = 0;
        int qtIgualMedia = 0;
	int count = 0;
        
	int *valoresPointer;

	float mediaValores = 0;

	printf("Informe a quatidade de valores a serem inseridos: ");
	scanf("%i", &qtValores);
	valoresPointer = (int *) malloc(qtValores*sizeof(int));

	while(count < qtValores) {
		printf("Valor %i: ", count+1);
		scanf("%i", &valoresPointer[count]); 
                qtLido = qtLido + 1;
                mediaValores = calculaMedia(valoresPointer, qtLido);
                
                if(mediaValores<valoresPointer[count]) {
                    qtMaiorQueMedia++;
                }
                if(mediaValores>valoresPointer[count]) {
                    qtMenorQueMedia++;
                    
                }
                if(mediaValores==valoresPointer[count]) {
                    qtIgualMedia++;                    
                }
                
                printf("    Media: %.2f\n", mediaValores);
                printf("    Qt maior que media: %i\n", qtMaiorQueMedia);
                printf("    Qt menor que media: %i\n", qtMenorQueMedia);
                printf("    Qt igual a media: %i\n", qtIgualMedia);
                printf("\n");
		count++;
	}
        printf("valores inseridos = {");
        for(count=0; count<qtValores; count++) {
            printf("%i, ", valoresPointer[count]);
        }
        printf("}\n");
	free(valoresPointer);

	return EXIT_SUCCESS;
}

float calculaMedia(int* vetor, int qtLidos) {
    int i;
    float s = 0;
    for(i=0; i<qtLidos; i++) {
        s += vetor[i];
    }
    return s/qtLidos;
}

