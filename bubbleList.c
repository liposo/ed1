#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct LISTA {
    int valor;
    struct LISTA *proximo;
};

typedef struct LISTA LISTA;

void push(LISTA **li, int val);
void imprimeLista(LISTA *lista);
void listFree(LISTA *lista);
void imprimeLista(LISTA *lista);
LISTA* bubbleSort( LISTA *l );
LISTA* troca( LISTA *l1, LISTA *l2);

int main(void) {

    LISTA *l = NULL;

    int listSize = 0;
    int i = 0;
    int randVal = 0;
    clock_t s,f;

    printf("Informe o tamanho da lista: ");
    scanf("%i", &listSize);

    srand(time(NULL));
    for(i=0; i<listSize; i++) {
        randVal = rand()%100;
        push(&l, randVal);
    }

    printf("\n");
    printf("Lista desordenada: ");
    imprimeLista(l);

    s = clock();
    LISTA *ord = bubbleSort(l);
    f = clock();
    printf("\n");
    printf("Lista ordenada: ");
    imprimeLista(l);

    float t = (f-s)*1000/CLOCKS_PER_SEC;
    printf("\nTempo: %.2f\n", t);

    listFree(l);
    listFree(ord);

    return 0;
}

void imprimeLista(LISTA *lista) {
    LISTA *l = lista;
    printf("{");
    while (l != NULL) {
        if(l->proximo != NULL) {
            printf("%i, ", l->valor);
            l = l->proximo;
        } else {
            printf("%i", l->valor);
            l = l->proximo;
        }
    }
    printf("}\n\n");
}

void listFree(LISTA *lista) {
    LISTA *l = lista;
    while(l != NULL) {
        LISTA *aux = l->proximo;
        free(l);
        l = aux;
    }
}

void push(LISTA** li, int val) {
    LISTA *node_new = malloc(sizeof(LISTA));

    node_new -> valor = val;
    node_new -> proximo = *li;
    *li = node_new;
}

LISTA* bubbleSort( LISTA *l ) {

    LISTA *p = NULL, *q = NULL, *top = NULL;
    int trocou = 1;

    if((top = (LISTA*)malloc(sizeof(LISTA))) == NULL) {
        printf("Malloc Failed!\n");
        exit(1);
    }

    top->proximo = l;

    if(l != NULL && l->proximo != NULL) {
        while(trocou) {
            trocou = 0;
            q = top;
            p = top->proximo;

            while(p->proximo != NULL) {
                if(p->valor > p->proximo->valor) {
                    q->proximo = troca(p, p->proximo);
                    trocou = 1;
                }
                q = p;
                if(p->proximo != NULL) {
                    p = p->proximo;
                }
            }
        }
    }

    p = top->proximo;
    free(top);
    return p;
}

LISTA* troca( LISTA *l1, LISTA *l2) {
    l1->proximo = l2->proximo;
    l2->proximo = l1;
    return l2;
}
