#include <stdio.h>
#include <stdlib.h>

int main(){

    int colunamax;
    printf("(n inteiro) Insira a dimensao x (coluna) da matriz que passara pela convolucao:\n");
    scanf("%i", &colunamax);

    int linhamax;
    printf("(n inteiro) Insira a dimensao y (linhas) da matriz que passara pela convolucao:\n");
    scanf("%i", &linhamax);

    int matriz[linhamax][colunamax];

    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            printf("Digite os valores para matriz[%i][%i]\n", l, c);
            scanf("%i", &matriz[l][c]);
        }
    }

    printf("\n");
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            printf("%i\t", matriz[l][c]);
        }
        printf("\n");
    }

    int var;
    printf("\nMatrizes para a convolucao:\n");
    printf("1 - realcar bordas:\n");
    printf("2 - detectar bordas:\n");
    printf("3 - outra forma de detectar bordas:\n");
    printf("4 - destacar relevo:\n");
    scanf("%i", &var);
    switch(var){
        case 1:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0){
                        matriz[l][c]=0;
                    }
                    printf("%i\t", matriz[l][c]);
                }
            printf("\n");
            }
            break;
    }
    return 0;
}