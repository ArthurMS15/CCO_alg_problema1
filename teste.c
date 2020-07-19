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
    printf("1 - realcar bordas (3x3):\n");
    printf("2 - detectar bordas (3x3):\n");
    printf("3 - outra forma de detectar bordas (3x3):\n");
    printf("4 - destacar relevo (3x3):\n");
    printf("5 - destacar objetos (3x3):\n");
    printf("6 - exemplo do trabalho (3x3):\n");
    printf("7 - desfocar a imagem (5x6):\n");
    printf("0 - para finalizar o programa\n");
    scanf("%i", &var);
    switch(var){
        case 1:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0){
                        matriz[l][c]=0;
                    }
                    else{
                        matriz[l][c]=((matriz[l-1][c-1]*0)+(matriz[l-1][c]*0)+(matriz[l-1][c+1]*0)+(matriz[l][c-1]*-1)+(matriz[l][c]*1)+(matriz[l][c+1]*0)+(matriz[l+1][c-1]*0)+(matriz[l+1][c]*0)+(matriz[l+1][c+1]*0));
                    }
                    printf("%i\t", matriz[l][c]);
                }
            printf("\n");
            }
            break;
    }
    return 0;
}