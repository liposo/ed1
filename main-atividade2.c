/*
 Aluno: Felipe Zanella Bourscheid
 Compilador: GCC
 
 */


#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    struct lista *proximo;
};

typedef struct lista Lista;

Lista* criaLista(void);
//Lista* insereNaLista(Lista *lista, int valor);
Lista* inserirOrdenado(Lista *lista, int valor);
void imprimeLista(Lista *lista);
void listFree(Lista *lista);

int main(int argc, char** argv) {
    
    int valor = 0;
    int qtValor = 0;
    
    Lista *lista;
    lista = criaLista();
    
    printf("Informe um valor inteiro positivo (para encerrar insira um valor negativo).\n");
    printf("valor %i: <= ", qtValor+1); scanf("%i", &valor);
    lista = inserirOrdenado(lista, valor);
    qtValor++;
    //printf("Valor inserido: %i\n", lista->valor);
    while(valor>=0) {
        printf("valor %i: <= ", qtValor+1); scanf("%i", &valor);
        if(valor>=0) {
            lista = inserirOrdenado(lista, valor);
            qtValor++;
            //printf("Valor inserido: %i\n", lista->valor);
        } else {
            break;
        }
    }
    
    imprimeLista(lista);
    
    free(lista);
    
    return (EXIT_SUCCESS);
}

void listFree(Lista *lista) {
    Lista *l = lista;
    while(l != NULL) {
        Lista *aux = l->proximo;
        free(l);
        l = aux;
    }
}

Lista* criaLista(void) {
    return NULL;
}

//Lista* insereNaLista(Lista *lista, int valor) {
//    Lista *novaLista = (Lista *) malloc(sizeof(lista));
//    novaLista->valor = valor;
//    novaLista->proximo = lista;
//    return novaLista;
//}

Lista* inserirOrdenado(Lista *lista, int valor) {
    Lista *novo;
    Lista *anterior = NULL; //ponteiro para o elemento anterior.
    Lista *p = lista;       //ponteiro para percorrer a lista.
    
    //procurar posição para inserção
    while(p != NULL && p->valor < valor) {
        anterior = p;
        p = p->proximo;
    }
    
    //cria novo elemento
    novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    
    //encadeia elemento
    if(anterior == NULL) { //insere no inicio.
        novo->proximo = lista;
        lista = novo;
    } else { //insere no meio da lista
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    return lista;
}

void imprimeLista(Lista *lista) {
    Lista *l = lista;
    printf("Valores inseridos ordenados = {");
    while (l != NULL) {
        if(l->proximo != NULL) {
            printf("%i, ", l->valor);
            l = l->proximo;
        } else {
            printf("%i", l->valor);
            l = l->proximo;
        }
    }
    printf("}.");
}


