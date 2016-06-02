#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node{
    struct node *prox;
    struct node *antes;
    int info;
}node;
typedef struct _list{
	struct node *first;
	struct node *last;
}list;

node *partition(geral *ponteiro, node *first, node *last) {
    node *pivot, *j, *i;
    i = first;
    j = last;
    int t;
   //int pivot, i, j, t;
   if (ponteiro != NULL)
   pivot = ponteiro->inicio;
   //i = l; j = r+1;

   while(1)
   {
   	do first->next;
   	while( i->info <= pivot->info && i <= last );

   	do j = j->antes;
   	while( j->info > pivot->info );

   	if( i >= j ) break;
   	t = i->info; i->info  = j->info ; j->info = t;
   }
   //t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}
void quickSort( geral *ponteiro, node *first, node *last){
   node *j;

   if( first != last ){
		j = partition(ponteiro, first, last);
		quickSort(ponteiro, first, j->antes);
		quickSort(ponteiro, j->next, last);
   }

}
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

    return 0;
}
