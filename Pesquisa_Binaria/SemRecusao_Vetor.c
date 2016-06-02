#include <stdio.h>
#include <stdlib.h>
int pesquisa_bin (int vetor[], int inicio, int fim, int busca){
    int meio;
    while(inicio <= fim){
        meio = (inicio + fim )/ 2;
        if (vetor[meio] == busca) return meio;
        if (vetor[meio] > busca)fim = meio-1;
        else inicio = meio + 1;
    }
    return -1;
}
int main()
{
    int vetor[10], i;
    for (i = 0; i < 10; i++){
        scanf(" %d", &vetor[i]);
    }
    // COLOCAR FUNCAO P ORGANIZAR EM ROL
    int posicao = pesquisa_bin(vetor, 0, 10, 8);
    if (posicao < 0) printf("Valor nao encontrado\n");
    else printf("Valor encontado na pos %d\n", posicao);
    return 0;
}
