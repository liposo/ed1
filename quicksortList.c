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
int ListLength (LISTA *lista);
LISTA* SelectPivot(LISTA *lista);
LISTA* quickSort(LISTA *lista);

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
    LISTA *ord = quickSort(l);
    f = clock();
    printf("\n");
    printf("Lista ordenada: ");
    imprimeLista(ord);

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

int ListLength (LISTA *lista) {
    LISTA *temp = lista;
    int i=0;

    while(temp!=NULL) {
        i++;
        temp=temp->proximo;
    }
    return i;
}

LISTA* SelectPivot(LISTA *lista) {
    int k, n, i = 0;
    n = ListLength(lista);
    LISTA *pivot = lista;

    k=rand()%n;  //

    for (; i < k; ++i) {
        pivot=pivot->proximo;
    }
    return pivot;
}

LISTA* quickSort(LISTA *lista) {
    // Return lista NULL
    if (ListLength(lista) <= 1) return lista;
    LISTA *less=NULL, *more=NULL, *next, *end, *temp=NULL;

    // Seleciona um pivo aleatorio
    LISTA *pivot = SelectPivot(lista);

    // Remove pivo da lista
    while(lista !=NULL) {
        next = lista->proximo;

        if(lista->valor != pivot->valor) {
            lista->proximo=temp;
            temp = lista;
        }
        lista = next;
    }
    // Divide
    while(temp != NULL) {
        next = temp->proximo;
        if(temp->valor <= pivot->valor) {
            temp->proximo = less;
            less = temp;
        } else if (temp->valor >= pivot->valor) {
            temp->proximo = more;
            more = temp;
        }
        temp = next;
    }

    // Chamadas recursivas
    less = quickSort(less);
    more = quickSort(more);

    // Merge!!!
    if(less != NULL) {
        end = less;
        while(end->proximo != NULL) {
            end=end->proximo;
        }
        pivot->proximo=more;
        end->proximo = pivot;
        return less;
    } else {
        pivot->proximo = more;
        return pivot;
    }
}
