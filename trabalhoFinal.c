#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _contato {
    char nome[45];
    char fone[30];
    struct _contato *proximo;
}TpContato;

typedef struct _lista {
    TpContato info;
    struct _lista *proximo;
}ListaContato;

const char *nomes[] = {"Miguel","Davi","Arthur","Gabriel","Pedro","Lucas","Matheus","Bernardo","Rafael",
"Guilherme","Enzo","Felipe","Gustavo","Nicolas","Heitor","Samuel","Joao Pedro","Pedro Henrique","Caua",
"Henrique","Murilo","Eduardo","Vitor","Daniel","Lorenzo","Vinicius","Pietro","Joao Vitor","Leonardo",
"Theo","Caio","Isaac","Lucca","Joao","Davi Lucas","Enzo Gabriel","Yuri","Bryan","Thiago","Joao Gabriel",
"Benjamin","Joaquim","Emanuel","Thomas","Ryan","Carlos Eduardo","Rodrigo","Ian","Fernando","Bruno","Otavio",
"Francisco","Calebe","Igor","Antonio","Erick","Joao Lucas","Luiz Felipe","Andre","Davi Lucca","Kaique",
"Nathan","Luiz Miguel","Breno","Vitor Hugo","Joao Guilherme","Benicio","Augusto","Joao Miguel","Pedro Lucas",
"Levi","Anthony","Yago","Danilo","Juan","Kaue","Diego","Vicente","Davi Luiz","Luiz Gustavo","Alexandre","Raul",
"Luan","Diogo","Marcelo","Ricardo","Luiz Henrique","Henry","Noah","Enrico","Lucas Gabriel","Renan","Luiz Otavio",
"Pedro Miguel","William","Icaro","Giovanni","Joao Paulo","Paulo","Adryan","Sophia","Julia","Alice","Manuela",
"Isabella","Laura","Maria Eduarda","Giovanna","Valentina","Beatriz","Luiza","Helena","Maria Luiza","Isadora",
"Mariana","Gabriela","Ana Clara","Rafaela","Maria Clara","Isabelly","Yasmin","Ana Julia","Livia","Lara",
"Lorena","Heloisa","Melissa","Sarah","Ana Luiza","Leticia","Nicole","Ana Beatriz","Emanuelly","Esther",
"Lavinia","Marina","Cecilia","Rebeca","Vitoria","Maria Fernanda","Larissa","Clara","Carolina","Bianca",
"Alicia","Fernanda","Gabrielly","Catarina","Ana Laura","Emilly","Eduarda","Amanda","Pietra","Agatha",
"Milena","Maria Alice","Lais","Maria Julia","Maria","Elisa","Stella","Maria Vitoria","Bruna","Ana Sophia",
"Barbara","Maria Cecilia","Olivia","Nathalia","Camila","Ana Carolina","Maite","Eloa","Luana","Luna","Ana Livia",
"Brenda","Alana","Sophie","Ana","Isabel","Mirella","Juliana","Marcela","Isis","Iara","Antonia","Kamilly","Alexia",
"Lis","Maria Sophia","Joana","Clarice","Ayla","Caroline","Antonella","Evellyn","Malu","Maria Laura","Mikaela","Stefany"};

void menu(void);
void listFree(ListaContato *lista);
void imprimeLista(ListaContato *contatos);
ListaContato* insereNaLista(ListaContato *contatos);
ListaContato* criaListaContatos(ListaContato *contatos, int tamanho);
ListaContato* insertionSort(ListaContato *contatos);

int main(void) {

    srand(time(NULL));
    clock_t s,f;

    int op = 0;
    int tamanho = 0;
    int i = 0;
    char escolha = 0;

    ListaContato *contatos = NULL;
    ListaContato *insertion = NULL;
    ListaContato *quick = NULL;
    ListaContato *selection = NULL;
    ListaContato *merge = NULL;

    do {
        menu();
        scanf(" %i", &op);
        switch(op) {
            case 1:
                if(!contatos) {
                    printf("\nInforme o tamanho da lista:");
                    scanf(" %i", &tamanho);
                    contatos = criaListaContatos(contatos, tamanho);
                    printf("\n -- Lista original --\n");
                    imprimeLista(contatos);
                    break;
                }
                if(contatos) {
                    printf("\nLista ja existente\n");
                    imprimeLista(contatos);
                    printf("\nDeseja criar uma lista nova? (S)im  (N)ao:\n");
                    scanf(" %c", &escolha);
                    switch(escolha) {
                        case 's':
                        case 'S':
                            free(contatos);
                            contatos = NULL;
                            printf("\nInforme o tamanho da nova lista:");
                            scanf(" %i", &tamanho);
                            contatos = criaListaContatos(contatos, tamanho);
                            printf("\n -- Nova Lista original --\n");
                            imprimeLista(contatos);
                            break;
                        case 'n':
                        case 'N':
                            break;
                        default:
                            printf("\nEntrada invalida!!\n");
                    }
                }
            case 2:
                if(!contatos) {
                    printf("\nLista inexistente\n");
                    break;
                } else {
                    insertion = contatos;
                    s = clock();
                    insertion = insertionSort(insertion);
                    f = clock();
                    printf("\n -- InsertionSort --\n");
                    imprimeLista(insertion);
                    float t = (f-s)*1000/CLOCKS_PER_SEC;
                    printf("Tempo: %.2f segs.\n", t/1000);
                    break;
                }
            case 3:
                if(!contatos) {
                    printf("\nLista inexistente\n");
                    break;
                } else {
                    selection = contatos;
                    s = clock();

                    f = clock();
                    printf("\n -- SelectionSort --\n");
                    imprimeLista(selection);
                    float t = (f-s)*1000/CLOCKS_PER_SEC;
                    printf("Tempo: %.2f segs.\n", t/1000);
                    break;
                }
                break;
            case 4:
                if(!contatos) {
                    printf("\nLista inexistente\n");
                    break;
                } else {
                    quick = contatos;
                    s = clock();

                    f = clock();
                    printf("\n -- QuickSort --\n");
                    imprimeLista(quick);
                    float t = (f-s)*1000/CLOCKS_PER_SEC;
                    printf("Tempo: %.2f segs.\n", t/1000);
                    break;
                }
                break;
            case 5:
                if(!contatos) {
                    printf("\nLista inexistente\n");
                    break;
                } else {
                    merge = contatos;
                    s = clock();

                    f = clock();
                    printf("\n -- MergeSort --\n");
                    imprimeLista(selection);
                    float t = (f-s)*1000/CLOCKS_PER_SEC;
                    printf("Tempo: %.2f segs.\n", t/1000);
                    break;
                }
                break;
            case 6: return(0);
            default:
                printf("\nEntrada invalida!!\n");
        }
    } while(op != 6);

    listFree(contatos);
    listFree(insertion);
    listFree(quick);
    listFree(selection);
    listFree(merge);
    return 0;
}

/** FREE LISTA  **/
void listFree(ListaContato *lista) {
    ListaContato *l = lista;
    while(l != NULL) {
        ListaContato *aux = l->proximo;
        free(l);
        l = aux;
    }
}

/** CRIA LISTA  **/
ListaContato* criaListaContatos(ListaContato *contatos, int tamanho) {
    int i = 0;
    for(i=0; i<tamanho; i++) {
        contatos = insereNaLista(contatos);
    }
    return contatos;
}

/** INSERE DADOS RANDOMICOS NA LISTA **/
ListaContato* insereNaLista(ListaContato *contatos) {
    ListaContato *novo = (ListaContato*) malloc(sizeof(ListaContato));

    if(!novo) {
        printf("\nErro - Falha ao tentar alocar.\n");
        exit(1);
    }

    int n = (rand() % (9998+1-1000))+1000;
    int f = (rand() % (999999998+1-100000000))+100000000;

    char nstr[40];
    char fstr[30];
    char nome[40];
    strcpy(nome, nomes[rand()%200]);

    sprintf(nstr, "%s %d",nome, n);
    sprintf(fstr,"%d", f);

    strcpy(novo->info.nome, nstr);
    strcpy(novo->info.fone, fstr);
    novo->proximo = contatos;

    return novo;
}

/** IMPRIME LISTA **/
void imprimeLista(ListaContato *contatos) {
    ListaContato *l = contatos;

    printf("\n");
    printf("--------------------\n");
    while (l != NULL) {
        printf("Nome: %s\n", l->info.nome);
        printf("Fone: %s\n", l->info.fone);
        printf("--------------------\n");
        l = l->proximo;
    }
    printf("\n");
}
/** MENU **/
void menu(void) {
    printf("\n  --- Menu ---\n");
    printf("1) Criar Lista\n");
    printf("2) Insertion Sort\n");
    printf("3) Selection Sort\n");
    printf("4) Quick Sort\n");
    printf("5) Merge Sort\n");
    printf("6) Sair\n");
    printf("\nSeleciona:");
}

/** INSERTION SORT **/
ListaContato* insertionSort(ListaContato *contatos) {
    if(!contatos || !contatos->proximo) {
        return contatos;
    }

    ListaContato *ordenado = NULL;

    while(contatos != NULL) {
        ListaContato *head = contatos;
        ListaContato **tail = &ordenado;

        contatos = contatos->proximo;

        while(!(*tail == NULL || (strcmp(head->info.nome, (*tail)->info.nome)<0))) {
            tail = &(*tail)->proximo;
        }
        head->proximo = *tail;
        *tail = head;
    }
    return ordenado;
}
