#include <stdio.h>
#include <stdlib.h>
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
LISTA* nodoDoMeio(LISTA *inicio ,LISTA *fim);
int binarySearch(LISTA *head, int val);

int main(void) {

    LISTA *l = NULL;

    int listSize = 0;
    int i = 0;
    int randVal = 0;
    int val = 0;
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

    printf("\n Informe o valor a ser buscado: ");
    scanf("%i", &val);
    if(binarySearch(ord, val) == 0) {
        printf("\n O valor: %i, esta na liista.\n", val);
    } else {
        printf("\n Valor nao encontrado!\n");
    }

    listFree(l);
    listFree(ord);

    return 0;
}

LISTA* nodoDoMeio(LISTA *inicio ,LISTA *fim) {
    if( inicio == NULL ) {
		//lista vazia
        printf("\n Lista vazia!! \n");
		return NULL;
	}

	LISTA *s = inicio;
	LISTA *f = fim -> proximo;

    /** A cada interação s anda uma posição enquanto que f anda duas**/
	while ( f != fim ) {
			f = f -> proximo;
			if( f != fim ) {
				s = s -> proximo;
				f = f -> proximo;
			}
	}
    /** No final s vai estar apontando para o nodo do meio da lista **/
	return s ;
}

int binarySearch(LISTA *l, int val) {
    LISTA *nodoInicial = l;
    LISTA *nodoFinal = NULL;

    do {
        LISTA *meio = nodoDoMeio(nodoInicial ,nodoFinal);

          if( meio == NULL ) {
              printf("\n Problemas em encontrar o meio!! \n");
              return 1;
          }

          if( meio->valor == val ) {
              return 0;
          } else if ( meio->valor < val ) {
               //busca nos maiores
               nodoInicial = meio->proximo;
          } else {
              //busca nos menores
              nodoFinal = meio;
          }
    } while(nodoFinal == NULL || nodoFinal->proximo != nodoInicial);

    //nada encontrado
    return 1;
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
