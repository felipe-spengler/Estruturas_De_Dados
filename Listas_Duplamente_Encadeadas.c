#include <stdio.h>
#include <stdlib.h>

typedef struct padrao {
    int numero;
    struct padrao *prox;
    struct padrao *antes;
}node;

typedef struct Lista{
    node *inicio;
    node *fim;
}lista;

void imprime_inicio (lista *p){
    node *aux = p->inicio;
    if(p->fim == NULL && p->inicio == NULL){
        printf("Lista Vazia\n");
    }else{
        for ( ; aux != NULL; aux = aux->prox){
            printf("Valor: %d\n", aux->numero);
        }
    }
}
void imprime_fim (lista *p){
    node *aux = p->fim;
    if(p->fim == NULL && p->inicio == NULL){
        printf("Lista Vazia\n");
    }else{
        for ( ; aux != NULL; aux = aux->antes){
            printf("Valor: %d\n", aux->numero);
        }
    }
}
lista *inicia_lista(){
    lista *L;
    L = malloc(sizeof(lista));
    L->fim = NULL;
    L->inicio = NULL;
    return L;
}
lista *insere_inicio(lista *p, int valor){
    node *aux;
    aux = (node *) malloc (sizeof(node));
    aux->numero = valor;
    aux->prox = NULL;
    aux->antes= NULL;
    if (p->inicio == NULL){
        p->inicio = aux;
        p->fim = aux;
    }else{
        p->inicio->antes = aux;
        aux->prox = p->inicio;
        p->inicio = aux;

    }
    return p;
}
lista *insere_fim(lista *p, int valor){
    node *aux;
    aux = (node *) malloc (sizeof(node));
    aux->numero = valor;
    aux->antes = p->fim;
    aux->prox = NULL;
    p->fim->prox = aux;
    p->fim = aux;

    return p;
}
lista *insere_meio(lista *p, int numeroIgual, int valor){
    node *aux = p->inicio;
    node *antes, *depois;
    for( ; aux->numero != numeroIgual && aux != NULL; aux = aux->prox);
    if (aux == p->fim){
        insere_fim(p, valor);
    }else{
        antes = aux;
        depois = aux->prox;
        aux = (node *) malloc (sizeof(node));
        antes->prox = aux;
        depois->antes = aux;
        aux->antes = antes;
        aux->prox = depois;
    }
    aux->numero = valor;
    return p;
}
lista *remover(lista *p, int valor){
    node *aux = p->inicio;
    node *antes_aux = NULL, *depois_aux = NULL;
    for( ; aux->numero != valor && aux != NULL; aux = aux->prox);
    if (aux->numero != valor){
        printf("Valor Nao Encontrado\n");
    }else{
        if (aux == p->inicio){
            if(aux->prox != NULL){
                aux->prox->antes = NULL;
                p->inicio = aux->prox;
            }
        }else if (aux == p->fim){
            aux->antes->prox = aux->prox;
            p->fim = aux->antes;
        }else{
            aux->antes->prox = aux->prox;
            aux->prox->antes = aux->antes;
        }
        free(aux);
    }
    return p;
}
int main()
{
    lista *p = NULL;
    p = inicia_lista();
    p = insere_inicio(p, 5);
    //remover(p, 5);
    p = insere_inicio(p, 4);
    p = insere_inicio(p, 3);
    p = insere_inicio(p, 2);
    p = insere_inicio(p, 1);
    p = insere_fim(p, 6);
    p = insere_meio(p, 3, 2);
    remover(p, 5);
    remover(p ,1);
    printf("\nImprime Inicio:\n");
    imprime_inicio(p);
    printf("\n\nImprime do Fim : \n");
    imprime_fim(p);

    return 0;
}
