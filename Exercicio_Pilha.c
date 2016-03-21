#include <stdio.h>
#include <stdlib.h>
void desempilha_palavra(int tamanho, char *frase, char *frase2){
    int i = 0, k = 0, j;
    tamanho--;
    while (tamanho > 0){
        if (frase[tamanho] == ' '){
            j = tamanho+1;
            while (frase[j] != ' ' && frase[j] != '\0'){

                frase2[k] = frase[j];
                j++;
                k++;
            }
            frase2[k] = frase[j];
            frase2[k] = ' ';
            k++;
        }
        tamanho--;
        i++;
    }
    while(frase[tamanho] != ' '){
        frase2[k] = frase[tamanho];
        tamanho++;
        k++;
    }
    frase2[k] = '\0';
}
void empilha_letras(int tamanho, char *frase, char *frase2){
    tamanho--;
    int i = 0;
    while (tamanho >= 0){
        frase[i] = frase2[tamanho];
        tamanho--;
        i++;
    }
}
int main()
{
    char *frase;
    char *frase2;
    char digitado;
    int tamanho = 0;
    frase = (char *) malloc(sizeof(char));
    while ((digitado = getchar()) != 10){
        frase = (char *) realloc(frase, (tamanho+1) * sizeof(char));
        if (frase == NULL){
            exit(1);
        }
        frase[tamanho] = digitado;
        tamanho++;
    }
    frase2 = (char *) malloc(tamanho * sizeof(char));
    frase[tamanho] = '\0';
    desempilha_palavra(tamanho, frase, frase2);
    empilha_letras(tamanho, frase, frase2);
    int i = 0;
    printf("\n");
    while (frase[i] != '\0'){
        printf("%c", frase[i]);
        i++;
    }
    printf("\n");
    return 0;
}
