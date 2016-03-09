#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void testePonteiro (int *pont){
    if (pont == NULL){
        printf("Memoria insuficiente\n");
        exit(1);
    }
}
int main()
{
    int **linhas;
    int *col_digitadas;
    int linha, coluna, i, j;
    srand( (unsigned)time(NULL) );

    printf("Digite linhas: ");
    scanf("%d", &linha);

    col_digitadas = (int *) malloc (linha * sizeof(int));
    testePonteiro(col_digitadas);
    linhas = (int *) malloc(linha * sizeof(int));
    testePonteiro(linhas);

    for (i = 0; i < linha; i++){
        coluna = rand() % 10;
        col_digitadas[i] = coluna;
        linhas[i] = (int *) malloc(coluna * sizeof(int));
        testePonteiro(linhas);
        for (j = 0; j < coluna; j++){
            printf("Preechendo linha %d coluna %d : ", i, j);
            scanf("%d", &linhas[i][j]);
        }
    }
    for (i = 0; i < linha; i++){
        coluna = col_digitadas[i];
        for (j = 0; j < col_digitadas[i]; j++){
            printf("Linha %d Coluna %d \n"
                   "Memoria %p Valor %d\n", i, j, &linhas[i][j], linhas[i][j]);

        }
    }
    return 0;
}
