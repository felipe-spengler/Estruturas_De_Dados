#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    struct node *prox;
    struct node *antes;
    int info;
}node;
void imprime (node *ponteiro){
    if (ponteiro == NULL){
		printf("Lista nulla");
	}else{
		for ( ; ponteiro != NULL; ponteiro = ponteiro->prox){
			printf(" %d ", ponteiro->info);
		}
	}
}

node *ordena_bubble (node *ponteiro){
  int troca = 0, valor_aux;
  node *node_aux;
  do{
    troca = 0;
    for (node_aux = ponteiro->prox; node_aux != NULL; node_aux = node_aux->prox){
      if (node_aux->info < node_aux->antes->info){
        troca = 1;
        valor_aux = node_aux->info;
        node_aux->info= node_aux->antes->info;
        node_aux->antes->info = valor_aux;

      }
    }

  }while (troca != 0);
  return ponteiro;
}

node *ordena_insertion (node *ponteiro){
    node *percorre = ponteiro->prox, *node_aux;
    int chave = 0;
    for ( ; percorre != NULL; percorre = percorre->prox){
        chave = percorre->info;
        node_aux = percorre->antes;
        while (node_aux != NULL && chave < node_aux->info){
            node_aux->prox->info = node_aux->info;
            node_aux = node_aux->antes;
        }
        if (node_aux == NULL) ponteiro->info = chave;
        else node_aux->prox->info = chave;
    }
    return ponteiro;
}
node *insere_valor (node *novo, int valor){
    node *aux = NULL;
    aux = malloc(sizeof(node));

    aux->prox = novo;
    aux->info = valor;
    aux->antes = NULL;

    if (novo != NULL) {
        novo->antes = aux;
    }
    return aux;
}

node *entrada_valores (){
    node *novo = NULL;
    int valor, i;
    //printf("Digite 5 valores:  ");
    for (i = 0; i < 20; i++){
        //scanf(" %d", &valor);
        valor = rand() %100;
        novo = insere_valor(novo, valor);
    }
    return novo;
}
int main()
{
    srand(time(NULL));
    node *ponteiro = NULL;
    clock_t cont_bolha, cont_insert;
    clock_t tempo[2];
    double Tempo;

    ponteiro = entrada_valores();
    printf("ADD: \n");
    imprime(ponteiro);

    tempo[0] = clock();
    printf("\n\nInsertion Sort: \n");
    ponteiro = ordena_insertion(ponteiro);
    imprime(ponteiro);
    tempo[1] = clock();

    Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n\n", Tempo);

    tempo[0] = clock();
    printf("\Bubble Sort: \n");
    ponteiro = ordena_bubble(ponteiro);
    imprime(ponteiro);
    tempo[1] = clock();

    Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n\n", Tempo);

    return 0;
}
