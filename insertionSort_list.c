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
LISTA* insertionSortList(LISTA* l);

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
    LISTA *ord = insertionSortList(l);
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

LISTA* insertionSortList(LISTA* l) {

  if(!l || !l->proximo)
      return l;

  LISTA *ordenado = NULL;

  while(l != NULL) {
      LISTA *head = l;
      LISTA **tail = &ordenado;

      l = l->proximo;

      while(!(*tail == NULL || head->valor < (*tail)->valor)) {
          tail = &(*tail)->proximo;
      }
      head->proximo = *tail;
      *tail = head;
  }

  return ordenado;
}
