/*
 Aluno: Felipe Zanella Bourscheid
 Compilador: GCC
 26/08/2015
 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct info {
    int id;
    char nome[30];
    double peso;
    double altura;
    double imc;
};

typedef struct info Info;

void showMenu();
void removePorId(Info** matriz);
void imprimePorId(Info** matriz);
void alteraPorId(Info** matriz);
void imprimeTudo(Info** matriz);
void matrizInit(Info** matriz);
void inserir(int count, Info** matriz);
void mostraMedias(Info** matriz);
void removePorNome(Info** matriz);


int main(void) {

    Info *matriz[MAX];
    matrizInit(matriz);
 
    int op = 0;
    int i = 0;
    int count = 0;
    
    do {
        showMenu(); scanf(" %i", &op);
        
        switch (op) {
            case 1:
                inserir(count, matriz);
                count = count + 1;
                break;

            case 2:
                imprimePorId(matriz);
                break;

            case 3:
                imprimeTudo(matriz);    
                break;

            case 4:
                removePorNome(matriz);
            break;

            case 5:
                removePorId(matriz);
                break;

            case 6:
                alteraPorId(matriz);
                break;

            case 7:
                mostraMedias(matriz);
                break;
        }
    } while(op != 0);
    
    return (EXIT_SUCCESS);
}

void matrizInit(Info** matriz) {
    int i;
    for(i=0; i<MAX; i++) {
        matriz[i] = NULL;
    }
}

void showMenu() {
    printf("# ------ Menu ------ #\n");
    printf("1 - Cadastrar usuario.\n");
    printf("2 - Listar dados de usuario.\n");
    printf("3 - Listar todos usuarios cadastrados.\n");
    printf("4 - Remover usuario por nome.\n");
    printf("5 - Remover usuario por indice.\n");
    printf("6 - Alterar dados de usuarios(nome, peso, altura).\n");
    printf("7 - Mostar IMC medio.\n");
    printf("0 - Sair.\n");
    printf("\nSelect: ");
}

void inserir(int count, Info** matriz) {
    
    int nova_posicao;
    
    if(count<0 || count>=MAX) {
        printf("Indice fora do limite!\n");
        return;
    }
    
    for(nova_posicao=0; nova_posicao<MAX; nova_posicao++) {
        if(matriz[nova_posicao] == NULL) {
            matriz[nova_posicao] = (Info*) malloc(sizeof(Info));
            break;
        }
    }
    
    printf(" \n# ------ Inserir ------ #\n");
    matriz[nova_posicao]->id = count;
    
    printf("Nome: "); 
    scanf(" %30[^\n]", matriz[nova_posicao]->nome);
    
    printf("Peso: "); 
    scanf("%lf", &matriz[nova_posicao]->peso);
    
    printf("Altura: "); 
    scanf("%lf", &matriz[nova_posicao]->altura);
    
    matriz[nova_posicao]->imc = matriz[nova_posicao]->peso/(matriz[nova_posicao]->altura * matriz[nova_posicao]->altura);
    
    printf("\n------ Inserido ------\n");
    printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
    printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n\n", matriz[nova_posicao]->id, matriz[nova_posicao]->nome, matriz[nova_posicao]->peso, matriz[nova_posicao]->altura, matriz[nova_posicao]->imc);
}

void alteraPorId(Info** matriz) {
    int id;
    printf(" \n# ------ Altera informacoes por ID ------ #\n");
    printf("ID: "); 
    scanf("%i", &id);
    
    if(id<0 || id>=MAX) {
        printf("\nIndice fora do limite!\n");
        return;
    }
    
    int i, pos;
    for(i=0; i<MAX; i++) {
        if(matriz[i] != NULL && matriz[i]->id == id) {          
            pos = i;
            break;
        }
    }
    if(pos!=i) {
        printf("\nID nao encontrado!\n");
        return;
    }
    char confirma;
    
    printf("Deseja Alterar:\n");
    printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
    printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n\n", matriz[pos]->id, matriz[pos]->nome, matriz[pos]->peso, matriz[pos]->altura, matriz[pos]->imc);
    printf("(y/n): ");
    scanf(" %c",&confirma);
    if(confirma == 'y') {
        printf("Nome: "); 
        scanf(" %30[^\n]", matriz[pos]->nome);

        printf("Peso: "); 
        scanf("%lf", &matriz[pos]->peso);

        printf("Altura: "); 
        scanf("%lf", &matriz[pos]->altura);

        matriz[pos]->imc = matriz[pos]->peso/(matriz[pos]->altura * matriz[pos]->altura);

        printf("\n------ Novas Informacoes ------\n");
        printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
        printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n\n", matriz[pos]->id, matriz[pos]->nome, matriz[pos]->peso, matriz[pos]->altura, matriz[pos]->imc);
    }
    if(confirma == 'n') {
        return;
    }
    printf("\n");
  
}

void removePorId(Info** matriz) {
    
    int id;
    printf(" \n# ------ Remover por ID ------ #\n");
    printf("ID: "); 
    scanf("%i", &id);
    
    if(id<0 || id>=MAX) {
        printf("\nIndice fora do limite!\n");
        return;
    }
    
    int i, pos;
    for(i=0; i<MAX; i++) {
        if(matriz[i] != NULL && matriz[i]->id == id) {          
            pos = i;
            break;
        }
    }
    if(pos!=i) {
        printf("\nID nao encontrado!\n");
        return;
    }
    
    char confirma;
    
    printf("Deseja remover:\n");
    printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
    printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n\n", matriz[pos]->id, matriz[pos]->nome, matriz[pos]->peso, matriz[pos]->altura, matriz[pos]->imc);
    printf("(y/n): ");
    scanf(" %c",&confirma);
    if(confirma == 'y') {
        free(matriz[pos]);
        matriz[pos] = NULL;
        printf("\nRemovido!\n");
    }
    if(confirma == 'n') {
        return;
    }
    printf("\n");
}

void removePorNome(Info** matriz) {
    char nome[30];
    int id;
    printf(" \n# ------ Remover por Nome ------ #\n");
    printf("Nome: "); 
    scanf(" %30[^\n]", nome);
    
    if(id<0 || id>=MAX) {
        printf("\nIndice fora do limite!\n");
        return;
    }

    int i, pos, rc;
    for(i=0; i<MAX; i++) {
        if(matriz[i] != NULL) {
            rc = strcmp(nome, matriz[i]->nome);
            if(rc == 0) {
                pos = i;
                break;
            }
        }
    }
    if(pos!=i) {
        printf("\nID nao encontrado!\n");
        return;
    }
    
    char confirma;
    printf("Deseja remover:\n");
    printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
    printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n\n", matriz[pos]->id, matriz[pos]->nome, matriz[pos]->peso, matriz[pos]->altura, matriz[pos]->imc);
    printf("(y/n): ");
    scanf(" %c",&confirma);
    if(confirma == 'y') {
        free(matriz[pos]);
        matriz[pos] = NULL;
        printf("\nRemovido!\n");
    }
    if(confirma == 'n') {
        return;
    }
    printf("\n");
}

void imprimePorId(Info** matriz) {
    
    int id;
    printf(" \n# ------ Informacoes por ID ------ #\n");
    printf("ID: "); 
    scanf("%i", &id);
    
    if(id<0 || id>=MAX) {
        printf("\nIndice fora do limite!\n");
        return;
    }
    
    int i, pos;
    for(i=0; i<MAX; i++) {
        if(matriz[i] != NULL && matriz[i]->id == id) {          
            pos = i;
            printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
            printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n", matriz[pos]->id, matriz[pos]->nome, matriz[pos]->peso, matriz[pos]->altura, matriz[pos]->imc);
            break;
        }
    }
    if(pos!=i) {
        printf("\nID nao encontrado!\n");
        return;
    }  
}

void imprimeTudo(Info** matriz) {
    int i;
    printf("\n------ Informacoes inseridas ------\n");
    printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
    for(i=0; i<MAX; i++) {
        if(matriz[i] != NULL) {
            printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n", matriz[i]->id, matriz[i]->nome, matriz[i]->peso, matriz[i]->altura, matriz[i]->imc);
        }
    }
    printf("\n");
}

void mostraMedias(Info** matriz) {
    int i, tot = 0;
    double pesos = 0, alturas = 0, imcs = 0;
    
    printf("%-10s%-35s%-15s%-15s%-15s\n", "ID", "Nome", "Peso", "Altura", "IMC");
    for(i=0; i<MAX; i++) {
        if(matriz[i] != NULL) {
            tot++;
            pesos = pesos+matriz[i]->peso;
            alturas = alturas+matriz[i]->altura;
            imcs = imcs+matriz[i]->imc;
            printf("%-10i%-35s%-15.2lf%-15.2lf%-15.2lf\n", matriz[i]->id, matriz[i]->nome, matriz[i]->peso, matriz[i]->altura, matriz[i]->imc);
        }
    }
    printf("\n%-10s%-35s%-15.2lf%-15.2lf%-15.2lf\n","", "Medias: ", pesos/tot, alturas/tot, imcs/tot);
    printf("\n");
}
