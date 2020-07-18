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
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            printf("%i\t", matriz[l][c]);
        }
        printf("\n");
    }

    printf("\nMatrizes para a convolucao:\n");
    printf("1 - realçar bordas:\n");
    
}