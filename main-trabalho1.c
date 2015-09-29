#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct conjunto {
    int valor;
    struct conjunto *proximo;
};

typedef struct conjunto Conjunto;

Conjunto* cria(void);
Conjunto* insereElementosOrdenados(Conjunto* conjunto, int valor);
void mainMenu(void);
void imprimeLista(Conjunto* conjunto);
void diferencaEntreConjuntos(Conjunto* c1, Conjunto* c2);
void uniaoEntreConjuntos(Conjunto* c1, Conjunto* c2);
void intersecaoEntreConjuntos(Conjunto* c1, Conjunto* c2);
int isPresent(Conjunto* conjunto, int val);


int main(void) {
    
    
    int mainop, op, elementValue, conjOp1, conjOp2, qtConjuntos, i, selConjunto;
    
    printf("Informe a quantidade de conjuntos: "); scanf("%i", &qtConjuntos);
    Conjunto *conjunto[qtConjuntos];
    for(i=0; i<qtConjuntos; i++) {
        conjunto[i] = cria();
    }
    selConjunto = 0;

    while(selConjunto < qtConjuntos) {
        printf("\n");
        printf("1-inserir elemento no conjunto %i\n", selConjunto);
        printf("2-sair\n");
        scanf("%i", &op);
        switch(op) {
            case 1:
                printf("=>"); scanf("%i", &elementValue);
                conjunto[selConjunto] = insereElementosOrdenados(conjunto[selConjunto], elementValue);
            break;
            case 2:
                selConjunto++;
            break;
        }
    }
    
    do {
        mainMenu();
        printf("Sel: "); scanf("%i", &mainop);
        if(mainop > 5 || mainop <= 0) {
            printf("\n Informe uma opcao valida. (1, 2, 3, 4, 5)\n");
            printf("Sel: "); scanf("%i", &mainop);
        }
        switch(mainop) {
            case 1:
                printf("\n");
                for(i=0; i<qtConjuntos; i++) {
                    printf("--- Valores no conjunto #%i ---\n", i);
                    imprimeLista(conjunto[i]);
                    printf("\n-------------------------------\n\n");
                }
                printf("\n\n");
                break;
            case 2:
                printf("\n Selecione os conjuntos para a operacao:\n");
                for(i=0; i<qtConjuntos; i++) {
                    printf("Conjunto - %i: ", i);
                    imprimeLista(conjunto[i]);
                    printf("\n\n");
                }
                printf("Conjunto 1: "); scanf("%i", &conjOp1);
                printf("\n");
                printf("Conjunto 2: "); scanf("%i", &conjOp2);
                diferencaEntreConjuntos(conjunto[conjOp1], conjunto[conjOp2]);
                printf("\n\n");
                break;
            case 3:
                printf("\n Selecione os conjuntos para a operacao:\n");
                for(i=0; i<qtConjuntos; i++) {
                    printf("Conjunto - %i: ", i);
                    imprimeLista(conjunto[i]);
                    printf("\n\n");
                }
                printf("Conjunto 1: "); scanf("%i", &conjOp1);
                printf("\n");
                printf("Conjunto 2: "); scanf("%i", &conjOp2);
                intersecaoEntreConjuntos(conjunto[conjOp1], conjunto[conjOp2]);
                printf("\n\n");
                break;
            case 4:
                printf("\n Selecione os conjuntos para a operacao:\n");
                for(i=0; i<qtConjuntos; i++) {
                    printf("Conjunto - %i: ", i);
                    imprimeLista(conjunto[i]);
                    printf("\n\n");
                }
                printf("Conjunto 1: "); scanf("%i", &conjOp1);
                printf("\n");
                printf("Conjunto 2: "); scanf("%i", &conjOp2);
                uniaoEntreConjuntos(conjunto[conjOp1], conjunto[conjOp2]);
                printf("\n\n");
                break;
            case 5:
                return (EXIT_SUCCESS);
        }
    }while(mainop != 5);
    
    return (EXIT_SUCCESS);
}

Conjunto* cria(void) {
    return NULL;
}

void diferencaEntreConjuntos(Conjunto* c1, Conjunto* c2) {
    Conjunto* p1;   //Ponteiro auxiliar para percorrer o conjunto 1
    Conjunto* p2;   //Ponteiro auxiliar para percorrer o conjunto 2
    Conjunto* resultante; //Conjunto resultate da diferença
    
    resultante = cria();
    
    p1 = c1;
    p2 = c2;
    
    while (p1 != NULL) {
        if(isPresent(c2, p1->valor)) {

        } else {
            if(isPresent(resultante, p1->valor)) {
            
            } else {
            resultante = insereElementosOrdenados(resultante, p1->valor);
            }
        }
        p1 = p1->proximo;
    }
    printf("--- Diferenca entre os conjuntos ---\n");
    imprimeLista(resultante);
}

void intersecaoEntreConjuntos(Conjunto* c1, Conjunto* c2) {
    Conjunto* p1;   //Ponteiro auxiliar para percorrer o conjunto 1
    Conjunto* p2;   //Ponteiro auxiliar para percorrer o conjunto 2
    Conjunto* resultante; //Conjunto resultate da diferença
    
    resultante = cria();
    p1 = c1;
    p2 = c2;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->valor == p2->valor) {
            if(isPresent(resultante, p1->valor)) {
                p1 = p1->proximo;
                p2 = p2->proximo;
            } else {
                resultante = insereElementosOrdenados(resultante, p1->valor);
                p1 = p1->proximo;
                p2 = p2->proximo;
            }
        }
        else if (p1->valor < p2->valor)    
            p1 = p1->proximo;
        else
            p2 = p2->proximo;
    }
    printf("--- intersecao entre os conjuntos ---\n");
    imprimeLista(resultante);
}

void uniaoEntreConjuntos(Conjunto* c1, Conjunto* c2) {
    Conjunto* p1;   //Ponteiro auxiliar para percorrer o conjunto 1
    Conjunto* p2;   //Ponteiro auxiliar para percorrer o conjunto 2
    Conjunto* resultante; //Conjunto resultate da diferença
    
    resultante = cria();
    
    p1 = c1;
    p2 = c2;
    
    while(p1 != NULL) {
        if(isPresent(resultante, p1->valor)){
            p1 = p1->proximo;
        } else {
            resultante = insereElementosOrdenados(resultante, p1->valor);
            p1 = p1->proximo;
        }
    }
    while(p2 != NULL) {
        if(isPresent(resultante, p2->valor)){
            p2 = p2->proximo;
        } else {
            resultante = insereElementosOrdenados(resultante, p2->valor);
            p2 = p2->proximo;
        }
    }
    printf("--- Uniao entre os conjuntos ---\n");
    imprimeLista(resultante);
}

void imprimeLista(Conjunto* conjunto) {
    Conjunto* p;    //Ponteiro auxiliar para percorrer a lista
    for(p = conjunto; p != NULL; p = p->proximo) {
        printf("%i ", p->valor);
    }
}

Conjunto* insereElementosOrdenados(Conjunto* conjunto, int valor) {
    Conjunto* novo;
    Conjunto* ant = NULL;   //Ponteiro para o elemento anterior
    Conjunto* p = conjunto; //Pontiero auxiliar para percorrer a lista
    
    /*Procurando local da inserção*/
    while(p != NULL && p->valor < valor) {
        ant = p;
        p = p->proximo;
    }
    
    /*Cria novo elemento*/
    novo = (Conjunto*) malloc(sizeof(Conjunto));
    novo->valor = valor;
    
    /*Encadeia o elemento*/
    if(ant == NULL) {   //Insere o elemento no início da lista
        novo->proximo = conjunto;
        conjunto = novo;
    } else {    //Insere no meio da lista
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }
    return conjunto;
}

int isPresent(Conjunto* conjunto, int val)
{
    Conjunto* conj = conjunto;
    while (conj != NULL)
    {
        if (conj->valor == val)
            return TRUE;
        conj = conj->proximo;
    }
    return FALSE;
}

void mainMenu(void) {
    printf("--- Menu: Conjuntos ---\n");
    printf("(1) - Mostrar conjuntos\n");
    printf("(2) - Diferenca entre dois conjuntos\n");
    printf("(3) - Intersecao entre dois conjuntos\n");
    printf("(4) - Uniao de dois conjuntos\n");
    printf("(5) - Sair\n");      
}