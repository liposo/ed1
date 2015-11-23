#include <stdio.h>
#include <stdlib.h>

struct lista {
    int valor;
    struct lista *proximo;
};
typedef struct lista Lista;

struct pilha {
    Lista *primeiro;
};
typedef struct pilha Pilha;

void mainMenu(void);
Pilha* criaPilha(void);
int popPilha(Pilha *p);
void pushPilha(Pilha *p, int valor);
void imprimePilha(Pilha *p);
int pilhaVazia(Pilha *p);
int buscaPilha(Pilha *p, int val);

int main(void) {

    srand(time(NULL));
    Pilha *p = NULL;
    int mainSelect = 0;
    int i;
    int insereInt = 0;
    int buscaInt = 0;
    int encontrado = 0;
    int removido = 0;
    int valorRand = 0;
    int qt = 0;

    p = criaPilha();

    do {
        mainMenu();
        scanf("%d", &mainSelect);
        if(mainSelect > 6) {
            printf("Entrada invalida, informe um valor de 1 a 6.\n");
            mainMenu();
            scanf("%d", &mainSelect);
        }
        switch (mainSelect) {
            case 1:
                if(pilhaVazia(p)) {
                    printf("Informe a quantidade de elementos a serem inseridos na pilha: ");
                    scanf("%d", &qt);
                    for(i=0; i<qt; i++) {
                        valorRand = rand()%100;
                        pushPilha(p, valorRand);
                    }
                    break;
                } else {
                    printf("Pilha ja populada!\n");
                    break;
                }

            case 2:
                printf("Informa o valor a ser inserido:\n");
                scanf("%d", &insereInt);
                pushPilha(p, insereInt);
                break;


            case 3:
                if(pilhaVazia(p)) {
                    printf("Pilha vazia!\n");
                    break;
                } else {
                    printf("Informe o valor a ser buscado: ");
                    scanf("%d", &buscaInt);
                    encontrado = buscaPilha(p, buscaInt);
                    if(encontrado > -1) {
                        printf("Valor encontrado na posicao %d. \n", encontrado);
                        break;
                    } else {
                        printf("Valor nao encontrado na pilha!\n");
                        break;
                    }
                }

            case 4:
                if(pilhaVazia(p)) {
                    printf("Pilha vazia!\n");
                    break;
                } else {
                    removido = popPilha(p);
                    printf("Valor removido: %d.\n", removido);
                    break;
                }

            case 5:
                if(pilhaVazia(p)) {
                    printf("Pilha vazia!\n");
                    break;
                } else {
                    imprimePilha(p);
                    break;
                }

            case 6:
                return 0;
        }

    } while(mainSelect != 6);

    free(p);
    return 0;
}

void mainMenu(void) {
    printf("\nMain menu Pilha com vetor\n");
    printf("1- Criar Pilha com valores aleatorios.\n");
    printf("2- Inserir valor manualmente.\n");
    printf("3- Buscar um valor na Pilha.\n");
    printf("4- Remover elemento da Pilha.\n");
    printf("5- Exibir a Pilha.\n");
    printf("6- Sair.\n");
    printf("Seleciona: ");
}

Pilha* criaPilha(void) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->primeiro = NULL;
    return p;
}

void pushPilha(Pilha* p, int valor) {
    Lista *n = (Lista*) malloc(sizeof(Lista));
    n->valor = valor;
    n->proximo = p->primeiro;
    p->primeiro = n;
}

int popPilha(Pilha *p) {
    Lista *t;
    int v;

    if(pilhaVazia(p)) {
        printf("Pilha Vazia!\n");
        return;
    }

    t = p->primeiro;
    v = t->valor;
    p->primeiro = t->proximo;

    free(t);
    return  v;
}

int pilhaVazia(Pilha *p) {
    return (p->primeiro == NULL);
}

void imprimePilha(Pilha *p) {
    Lista *t;
    printf("\n");
    for(t=p->primeiro; t!=NULL; t=t->proximo) {
        printf("[");
        printf("%d", t->valor);
        printf("]\n");
    }
    free(t);
}

int buscaPilha(Pilha *p, int valor) {
    Lista *t;
    int v;
    int cont = 0;
    for(t=p->primeiro; t!=NULL; t=t->proximo) {
        if(t->valor == valor) {
            return cont;
        }
        cont = cont + 1;
    }
    free(t);
    return -1;
}
