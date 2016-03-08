#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int i, valor, qnt = 0, saida = 0;
    char digitado[50];

    p = (int *) malloc(5 * sizeof(int));
    if (p == NULL){
        printf("\Memória insuficiente\n");
        exit(1);
    }
    do{
        setbuf(stdin, NULL);
        scanf("%s", digitado);
        i = 0;
        while (digitado[i] != '\0'){
            if (!(digitado[i] >= '0' && digitado[i] <= '9')){
                saida = 1;
                break;
            }
            i++;
        }
        if (saida != 1){
            if (qnt > 5){
                p = (int *) realloc(p,(qnt + 1) * sizeof(int));
               if (p == NULL){
                    printf("\Memória insuficiente\n");
                    exit(1);
                }
            }
            p[qnt] = atoi(digitado);
            qnt++;
        }


    }while (saida != 1);
    printf("Numeros lidos: ");

    for (i = 0; i < qnt; i++){
        printf("\nPos [%d] - %d", i, p[i]);
    }

    free(p);
    return 0;
}
