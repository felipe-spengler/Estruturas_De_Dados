#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node{
    struct _node *prox;
    struct _node *antes;
    int info;
} node;
typedef struct _list{
    struct _node *first;
    struct _node *last;
} list;

void imprime (list *ponteiro){
    node *aux = ponteiro->first;

    if (aux == NULL){
        printf("Lista nulla");
    }else{
        for ( ; aux != NULL; aux = aux->prox){
            printf(" %d ", aux->info);
        }
    }
}

void quick_sort(list *ponteiro, node *primeiro, node *ultimo) {
    node *i, *j, *pivo;
    int z;
    //int i, j, x, y;
    i = primeiro;
    j = ultimo;
    pivo = primeiro;

    while(i != j) {
        while(i->info < pivo->info && i != ultimo) {
            i = i->prox;
        }
        while(j->info > pivo->info && j != primeiro) {
            j = j->antes;
        }
        if(i != j) {
            z = i->info;
            i->info = j->info;
            j->info = z;
            i = i->prox;
            j = j->antes;
        }
    }
    // mudado > para !=
    if(j != primeiro) {
        quick_sort(ponteiro, primeiro, j);
    }
    // mudado < para !=
    if(i != ultimo) {
        quick_sort(ponteiro, i, ultimo);
    }
}

list *insere_valor (list *ponteiro, int valor){
    node *novo = NULL;
    novo = malloc (sizeof(node));

    if (novo == NULL) exit(1);

    novo->info = valor;
    novo->antes = NULL;
    if (ponteiro->first != NULL){
        novo->prox = ponteiro->first;
    }else{
        novo->prox = NULL;
        ponteiro->last = novo;
    }
    ponteiro->first = novo;

    return ponteiro;
}
list *entrada_valores (list *ponteiro){

    int valor, i;
    printf("Digite 5 valores:  ");
    for (i = 0; i < 5; i++){
        scanf(" %d", &valor);
        ponteiro = insere_valor(ponteiro, valor);
    }
    return ponteiro;
}
int main()
{

    list *ponteiro = NULL;
    ponteiro = malloc (sizeof(list));
    ponteiro->first = ponteiro->last = NULL;
    ponteiro = entrada_valores(ponteiro);
    printf("ADD: \n");
    imprime(ponteiro);
    printf("Quick: \n");
    quick_sort(ponteiro, ponteiro->first, ponteiro->last);

    return 0;
}
