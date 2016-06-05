#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    struct node *next;
    struct node *antes;
    int info;
} node;
typedef struct principal{
    struct node *inicio;
    struct node *fim;
}geral;

node *partition(node *first, node *last) {
    node *pivot = first, *esq = first->next, *dir = last;
    int t, chave = 1;

   if (first == NULL) return NULL;

   while(chave){
        while (esq->info < pivot->info){
            esq = esq->next;
        }
        while (dir->info > pivot->info){
            if (dir == esq) chave = 0;
            dir = dir->antes;
        }
        if (esq->info < dir->info){
            t = esq->info;
            esq->info = dir->info;
            dir->info = t;

        }
        if (chave == 0){
            t = pivot->info;
            pivot->info = dir->info;
            dir->info = t;
        }
   }
   return dir;
}
void imprime (geral *ponteiro){
    if (ponteiro == NULL){
        printf(" Null\n");
    }else{
        node *aux = ponteiro->inicio;
        for ( ; aux != NULL; aux = aux->next){
            printf(" %d ", aux->info);
        }
    }
}
geral *insere_valor (geral *ponteiro, int valor){
    node *novo = NULL;
    novo = malloc (sizeof(node));

    if (novo == NULL) exit(1);

    novo->info = valor;
    novo->antes = NULL;
    if (ponteiro->inicio != NULL){
        novo->next = ponteiro->inicio;
    }else{
        novo->next = NULL;
        ponteiro->fim = novo;
    }
    ponteiro->inicio = novo;

    return ponteiro;
}
geral *entrada_valores (geral *ponteiro){

    int valor, i;
    printf("Digite 5 valores:  ");
    for (i = 0; i < 5; i++){
        scanf(" %d", &valor);
        ponteiro = insere_valor(ponteiro, valor);
    }
    return ponteiro;
}
void quickSort(geral *ponteiro, node *first, node *last){
   node *j;

   if( first != last ){
        j = partition(first, last);
        quickSort(ponteiro, first, j->antes);
        quickSort(ponteiro, j->next, last);
   }
}

int main()
{
    geral *mestre = malloc (sizeof(geral));
    mestre->fim = mestre->inicio = NULL;

    mestre = entrada_valores(mestre);
    printf("Antes : \n");
    imprime(mestre);

    printf("Depois: \n");
    quickSort(mestre, mestre->inicio, mestre->fim);

    return 0;
}
