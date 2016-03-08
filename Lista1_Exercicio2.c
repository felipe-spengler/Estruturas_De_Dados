#include <stdio.h>
#include <stdlib.h>

int *funcao (int *vetor1, int quant1, int *vetor2, int quant2){
    int i , tamanho = quant1 + quant2;
    int gravar;
    int *vetor3 = (int *) malloc (tamanho * sizeof(int));
    for (i = 0; i < tamanho; i++){
        if (i < quant1){
            vetor3[i] = vetor1[i];
        }else{
            vetor3[i] = vetor2[i - quant1];
        }
    }
    return vetor3;
}
void preenche (int *vetor1, int quant1, int *vetor2,int quant2){
    int i;
    printf("Preencha 1o vetor: ");
    for (i = 0; i < quant1; i++){
        setbuf(stdin, NULL);
        scanf("%d", &vetor1[i]);
    }
    printf("Preencha 2o vetor: ");
    for (i = 0; i < quant2; i++){
        setbuf(stdin, NULL);
        scanf("%d", &vetor2[i]);
    }
}
void mostra (int *vetor3, int tam){
    int i;
    printf("\n");
    for (i = 0; i < tam; i++){
        printf("\nPos %d - 3o vetor:  %d\n", i, vetor3[i]);
    }
}
int main()
{
    int quant, quant2;
    printf("Digite quantidade de valores de cada vetor: ");
    scanf("%d %d", &quant, &quant2);

    int *vetor1, *vetor2, *vetor3;
    vetor1 = (int *) malloc(quant * sizeof(int));
    if (vetor1 == NULL){
        exit(1);
    }

    vetor2 = (int *) malloc(quant2 * sizeof(int));
    if (vetor2 == NULL){
        exit(1);
    }

    preenche (vetor1, quant, vetor2, quant2);
    vetor3 = funcao(vetor1, quant, vetor2, quant2);
    mostra(vetor3, quant + quant2);


    return 0;
}
