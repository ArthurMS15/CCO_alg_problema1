#include <stdio.h>
#include <stdlib.h>
#define TAM 256
#define LINHA 16
#define COLUNA 16

typedef struct{
    int linha;
    int coluna;
} sDimensaoMatriz; // *declaração do registro

int EscolhaLinhaMax(sDimensaoMatriz matriz1);
int EscolhaColunaMax(sDimensaoMatriz matriz1);
int** CriarMatriz(int linhamax, int colunamax);
int** CriarMatrizAuxiliar(int linhamax, int colunamax);
int EscolhaKernel();
void EscolhaValoresDentroMatriz(int linhamax, int colunamax, int **matriz);
void EscreverValoresDentroMatriz(int linhamax, int colunamax, int **matriz);
void ProcessoConvolucaoeEscolhaKernel(int linhamax, int colunamax, int **matriz, int **matrizaux);
void DesalocaMatrizeMatrizaux(int **matriz, int **matrizaux);
void KernelCaso1(int linhamax, int colunamax, int **matriz, int **matrizaux);
void KernelCaso2(int linhamax, int colunamax, int **matriz, int **matrizaux);
void KernelCaso3(int linhamax, int colunamax, int **matriz, int **matrizaux);
void KernelCaso4(int linhamax, int colunamax, int **matriz, int **matrizaux);
void KernelCaso5(int linhamax, int colunamax, int **matriz, int **matrizaux);
void KernelCaso6(int linhamax, int colunamax, int **matriz, int **matrizaux);
void FinalizarPrograma(); // *modularização(procedimento e de ação), prototipação

int main(){

    sDimensaoMatriz matriz1;
    int linhamax=EscolhaLinhaMax(matriz1); // *uso do registro
    int colunamax=EscolhaColunaMax(matriz1);

    int **matriz; // *uso de registro dentro de um registro
    matriz=CriarMatriz(linhamax, colunamax); //alocação dinâmica de memória
    int **matrizaux; 
    matrizaux=CriarMatrizAuxiliar(linhamax, colunamax); 

    EscolhaValoresDentroMatriz(linhamax, colunamax, matriz); // *passagem de parâmetro por valor e referência
    EscreverValoresDentroMatriz(linhamax, colunamax, matriz); 
    
    ProcessoConvolucaoeEscolhaKernel(linhamax, colunamax, matriz, matrizaux);
    DesalocaMatrizeMatrizaux(matriz, matrizaux);
    return 0;
}

int EscolhaLinhaMax(sDimensaoMatriz matriz1){
    printf("(Linha) numero aleatorio sendo gerado...\n");
    matriz1.linha=rand()%LINHA;
    return matriz1.linha;
}

int EscolhaColunaMax(sDimensaoMatriz matriz1){
    printf("(Coluna) numero aleatorio sendo gerado...\n");
    matriz1.coluna=rand()%COLUNA;
    return matriz1.coluna;
}

int** CriarMatriz(int linhamax, int colunamax){
    int **m;
    m=(int**) malloc(linhamax * sizeof(sizeof(int *)));
    for(int l=0; l<linhamax;l++){
        m[l]=(int*)malloc(colunamax * sizeof(int));
    }
    if (m == NULL){
        printf("Erro ao alocar memoria!\n");
    }
    return m;
}

int** CriarMatrizAuxiliar(int linhamax, int colunamax){
    int **maux;
    maux=(int**) malloc(linhamax * sizeof(sizeof(int *)));
    for(int l=0; l<linhamax;l++){
        maux[l]=(int*)malloc(colunamax * sizeof(int));
    }
    if (maux == NULL){
        printf("Erro ao alocar memoria!\n");
    }
    return maux;
}

int EscolhaKernel(){
    int var;
    printf("\nMatrizes para a convolucao:\n");
    printf("1 - realcar bordas (3x3):\n");
    printf("2 - detectar bordas (3x3):\n");
    printf("3 - outra forma de detectar bordas (3x3):\n");
    printf("4 - destacar relevo (3x3):\n");
    printf("5 - destacar objetos (3x3):\n");
    printf("6 - exemplo do trabalho (3x3):\n");
    printf("0 - para finalizar o programa\n");
    scanf("%i", &var);
    return var;
}

void EscolhaValoresDentroMatriz(int linhamax, int colunamax, int **matriz){
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            matriz[l][c]=rand()%TAM;
        }
    }
}

void EscreverValoresDentroMatriz(int linhamax, int colunamax, int **matriz){
    printf("MATRIZ:\n");
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            printf("%i\t", matriz[l][c]);
        }
        printf("\n");
    }
}

void ProcessoConvolucaoeEscolhaKernel(int linhamax, int colunamax, int **matriz, int **matrizaux){
    switch(EscolhaKernel()){
        case 1:
            KernelCaso1(linhamax, colunamax, matriz, matrizaux); // *passagem de parâmetro por valor e referência, elementos do registro
            break;
        case 2:
            KernelCaso2(linhamax, colunamax, matriz, matrizaux);
            break;
        case 3:
            KernelCaso3(linhamax, colunamax, matriz, matrizaux);
            break;
        case 4:
            KernelCaso4(linhamax, colunamax, matriz, matrizaux);
            break;
        case 5:
            KernelCaso5(linhamax, colunamax, matriz, matrizaux);
            break;
        case 6:
            KernelCaso6(linhamax, colunamax, matriz, matrizaux);
            break;
        case 0:
            FinalizarPrograma();
            break;
    }
}

void KernelCaso1(int linhamax, int colunamax, int **matriz, int **matrizaux){
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
}

void KernelCaso2(int linhamax, int colunamax, int **matriz, int **matrizaux){ 
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
}

void KernelCaso3(int linhamax, int colunamax, int **matriz, int **matrizaux){
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
}

void KernelCaso4(int linhamax, int colunamax, int **matriz, int **matrizaux){
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
}

void KernelCaso5(int linhamax, int colunamax, int **matriz, int **matrizaux){
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
}

void KernelCaso6(int linhamax, int colunamax, int **matriz, int **matrizaux){
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
}

void DesalocaMatrizeMatrizaux(int **matriz, int **matrizaux){
    printf("Desalocando memoria\n");
    free(matriz);
    free(matrizaux);
}

void FinalizarPrograma(){
    printf("PROGRAMA FINALIZADO\n");
}