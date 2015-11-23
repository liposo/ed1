#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct pilha {
    int valor[MAX];
    int n;
};

typedef struct pilha Pilha;

void mainMenu(void);
Pilha* criaPilha(void);
int pop(Pilha *p);
void push(Pilha *p, int valor);
void imprimePilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaBusca(Pilha *p, int val);

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
                    for(i=0; i<MAX; i++) {
                        valorRand = rand()%100;
                        push(p, valorRand);
                    }
                    break;
                } else {
                    printf("Pilha ja populada!\n");
                    break;
                }

            case 2:
                printf("Informa o valor a ser inserido:\n");
                scanf("%d", &insereInt);
                push(p, insereInt);
                break;


            case 3:
                if(pilhaVazia(p)) {
                    printf("Pilha vazia!\n");
                    break;
                } else {
                    printf("Informe o valor a ser buscado: ");
                    scanf("%d", &buscaInt);
                    encontrado = pilhaBusca(p, buscaInt);
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
                    removido = pop(p);
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
    p->n = 0;
    return p;
}

void push(Pilha *p, int valor) {
    if(p->n == MAX) {
        printf("Capacidade da Pilha esgotada!\n");
        return;
    }

    p->valor[p->n] = valor;
    p->n++;
}

int pop(Pilha *p) {
   if(pilhaVazia(p)) {
       printf("Pilha Vazia!\n");
       return;
   }

   int v = 0;

   v = p->valor[p->n-1];
   p->n--;
   return v;
}

void imprimePilha(Pilha *p) {
    int i;
    for(i = 0; i<p->n; i++) {
       printf("\n[");
       printf("%d ", p->valor[i]);
       printf("]\n");
    }
}

int pilhaVazia(Pilha *p) {
    return (p->n == 0);
}

int pilhaBusca(Pilha *p, int val) {
    if(pilhaVazia(p)) {
        printf("Pilha Vazia!\n");
        return;
    }

    int v= 0;
    int i = 0;

    for(i=0; i <= p->n; i++) {
        if(p->valor[i] == val) {
            return i;
        }
    }
    return -1;
}
