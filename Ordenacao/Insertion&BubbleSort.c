#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    struct node *prox;
    struct node *antes;
    int info;
}val;
void imprime (val *p){
    if (p == NULL){
		printf("Lista nulla");
	}else{
		for ( ; p != NULL; p = p->prox){
			printf(" %d ", p->info);
		}
	}
}

val *rol_bolha (val *p){
  int troca = 0, aux;
  val *i;
  do{
    troca = 0;
    for (i = p->prox; i != NULL; i = i->prox){
      if (i->info < i->antes->info){
        troca = 1;
        aux = i->info;
        i->info= i->antes->info;
        i->antes->info = aux;

      }
    }

  }while (troca != 0);
  return p;
}

val *rol_insertion (val *p){
    val *aux = p->prox, *i;
    int chave = 0;
    for ( ; aux != NULL;aux = aux->prox){
        chave = aux->info;
        i = aux->antes;
        while (i != NULL && chave < i->info){
            i->prox->info = i->info;
            i = i->antes;
        }
        if (i == NULL) p->info = chave;
        else i->prox->info = chave;
    }
    return p;
}
val *insere_valor (val *novo, int valor){
    val *aux = NULL;
    aux = malloc(sizeof(val));

    aux->prox = novo;
    aux->info = valor;
    aux->antes = NULL;

    if (novo != NULL) {
        novo->antes = aux;
    }
    return aux;
}

val *carrega (){
    val *novo = NULL;
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
    val *p = NULL;
    clock_t cont_bolha, cont_insert;
    clock_t tempo[2];
    double Tempo;

    p = carrega();
    printf("ADD: \n");
    imprime(p);

    tempo[0] = clock();
    printf("\n\nInsertion Sort: \n");
    p = rol_insertion(p);
    imprime(p);
    tempo[1] = clock();

    Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n\n", Tempo);

    tempo[0] = clock();
    printf("\Bubble Sort: \n");
    p = rol_bolha(p);
    imprime(p);
    tempo[1] = clock();

    Tempo = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.\n\n", Tempo);

    return 0;
}
