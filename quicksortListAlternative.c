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
LISTA *getTail(LISTA *cur);
LISTA *partition(LISTA *head, LISTA *end, LISTA **newHead, LISTA **newEnd);
LISTA *quickSortRecur(LISTA *head, LISTA *end);
void quickSort(LISTA **headRef);

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
    quickSort(&l);
    f = clock();
    printf("\n");
    printf("Lista ordenada: ");
    imprimeLista(l);

    float t = (f-s)*1000/CLOCKS_PER_SEC;
    printf("\nTempo: %.2f\n", t);

    listFree(l);

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

// Returns the last node of the list
LISTA *getTail(LISTA *cur)
{
    while (cur != NULL && cur->proximo != NULL)
        cur = cur->proximo;
    return cur;
}

// Partitions the list taking the last element as the pivot
LISTA *partition(LISTA *head, LISTA *end, LISTA **newHead, LISTA **newEnd)
{
    LISTA *pivot = end;
    LISTA *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->valor < pivot->valor)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->proximo;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to proximo of tail, and change tail
            if (prev)
                prev->proximo = cur->proximo;
            LISTA *tmp = cur->proximo;
            cur->proximo = NULL;
            tail->proximo = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot valor is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}


//here the sorting happens exclusive of the end node
LISTA *quickSortRecur(LISTA *head, LISTA *end)
{
    // base condition
    if (!head || head == end)
        return head;

    LISTA *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    LISTA *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        LISTA *tmp = newHead;
        while (tmp->proximo != pivot)
            tmp = tmp->proximo;
        tmp->proximo = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change proximo of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->proximo =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->proximo = quickSortRecur(pivot->proximo, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(LISTA **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
