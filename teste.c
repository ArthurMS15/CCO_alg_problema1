#include <stdio.h>
#include <stdlib.h>

int main(){

    int colunamax;
    printf("(n inteiro) Insira a dimensao x (coluna) da matriz que passara pela convolucao:\n");
    scanf("%i", &colunamax);

    int linhamax;
    printf("(n inteiro) Insira a dimensao y (linha) da matriz que passara pela convolucao:\n");
    scanf("%i", &linhamax);

    int matriz[linhamax][colunamax];
    int matrizaux[linhamax][colunamax];

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
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=((matriz[l-1][c-1]*0)+(matriz[l-1][c]*0)+(matriz[l-1][c+1]*0)+(matriz[l][c-1]*-1)+(matriz[l][c]*1)+(matriz[l][c+1]*0)+(matriz[l+1][c-1]*0)+(matriz[l+1][c]*0)+(matriz[l+1][c+1]*0));
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 2:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=((matriz[l-1][c-1]*0)+(matriz[l-1][c]*1)+(matriz[l-1][c+1]*0)+(matriz[l][c-1]*1)+(matriz[l][c]*-4)+(matriz[l][c+1]*1)+(matriz[l+1][c-1]*0)+(matriz[l+1][c]*1)+(matriz[l+1][c+1]*0));
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 3:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=((matriz[l-1][c-1]*-1)+(matriz[l-1][c]*-1)+(matriz[l-1][c+1]*-1)+(matriz[l][c-1]*-1)+(matriz[l][c]*8)+(matriz[l][c+1]*-1)+(matriz[l+1][c-1]*-1)+(matriz[l+1][c]*-1)+(matriz[l+1][c+1]*-1));
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 4:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=((matriz[l-1][c-1]*-2)+(matriz[l-1][c]*-1)+(matriz[l-1][c+1]*0)+(matriz[l][c-1]*-1)+(matriz[l][c]*1)+(matriz[l][c+1]*1)+(matriz[l+1][c-1]*0)+(matriz[l+1][c]*1)+(matriz[l+1][c+1]*2));
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 5:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=(matriz[l-1][c-1]*-1)+(matriz[l-1][c]*0)+(matriz[l-1][c+1]*0)+(matriz[l][c-1]*1)+(matriz[l][c]*0)+(matriz[l][c+1]*0)+(matriz[l+1][c-1]*0)+(matriz[l+1][c]*0)+(matriz[l+1][c+1]*0);
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 6:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=(matriz[l-1][c-1]*-1)+(matriz[l-1][c]*0)+(matriz[l-1][c+1]*1)+(matriz[l][c-1]*-2)+(matriz[l][c]*0)+(matriz[l][c+1]*2)+(matriz[l+1][c-1]*-1)+(matriz[l+1][c]*0)+(matriz[l+1][c+1]*1);
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 7:
            for(int l=0;l<linhamax;l++){
                for(int c=0;c<colunamax;c++){
                    if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                        printf("\t");
                    }
                    else{
                        matrizaux[l][c]=(matriz[l-2][c-2]*0)+(matriz[l-2][c-1]*0)+(matriz[l-2][c]*0)+(matriz[l-2][c+1]*0)+(matriz[l-2][c+2]*0)+(matriz[l-1][c-2]*0)+(matriz[l-1][c-1]*1)+(matriz[l-1][c]*1)+(matriz[l-1][c+1]*1)+(matriz[l-1][c+2]*0)+(matriz[l][c-2]*0)+(matriz[l][c+1]*1)+(matriz[l][c]*1)+(matriz[l][c+1]*1)+(matriz[l][c+2]*0)+(matriz[l+1][c-2]*0)+(matriz[l+1][c-1]*1)+(matriz[l+1][c]*1)+(matriz[l+1][c+1]*1)+(matriz[l+1][c+2]*0)+(matriz[l+2][c-2]*0)+(matriz[l+2][c-1]*0)+(matriz[l+2][c]*0)+(matriz[l+2][c+1]*0)+(matriz[l+2][c+2]*0);
                        printf("%i\t", matrizaux[l][c]);
                    }
                }
            printf("\n");
            }
            break;
        case 8:
            return 0;
            break;
    }
    return 0;
}