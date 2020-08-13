#include <stdio.h>
#include <stdlib.h>
#define TAM 256
#define LINHA 16
#define COLUNA 16

typedef struct{
    int linha;
    int coluna;
} sDimensaoMatriz; // *declaração do registro

int escolhaLinhaMax(sDimensaoMatriz matriz1);
int escolhaColunaMax(sDimensaoMatriz matriz1);
int** criarMatriz(int linhamax, int colunamax);
int escolhaKernel();
int** criarMatrizKernel();
void escolhaValoresDentroMatriz(int linhamax, int colunamax, int **matriz);
void escreverValoresDentroMatriz(int linhamax, int colunamax, int **matriz);
void escolhaValoresDentroKernel(int **kernel);
void processoConvolucaoeEscolhaKernel(int linhamax, int colunamax, int **matriz, int **matrizaux);
void desalocaMatrizeMatrizaux(int linhamax, int **matriz, int **matrizaux);
void kernelCaso1(int linhamax, int colunamax, int **matriz, int **matrizaux);
void finalizarPrograma(); // *modularização(procedimento e de ação), prototipação

int main(){

    sDimensaoMatriz matriz1;
    int linhamax=escolhaLinhaMax(matriz1); // *uso do registro
    int colunamax=escolhaColunaMax(matriz1);

    int **matriz; // *uso de ponteiro dentro de outro ponteiro
    matriz=criarMatriz(linhamax, colunamax); //alocação dinâmica de memória
    int **matrizaux; 
    matrizaux=criarMatriz(linhamax, colunamax); 

    escolhaValoresDentroMatriz(linhamax, colunamax, matriz); // *passagem de parâmetro por valor e referência
    escreverValoresDentroMatriz(linhamax, colunamax, matriz); 
    
    processoConvolucaoeEscolhaKernel(linhamax, colunamax, matriz, matrizaux);
    desalocaMatrizeMatrizaux(linhamax, matriz, matrizaux);
    return 0;
}

int escolhaLinhaMax(sDimensaoMatriz matriz1){
    printf("(Linha) numero aleatorio sendo gerado...\n");
    matriz1.linha=rand()%LINHA;
    return matriz1.linha;
}

int escolhaColunaMax(sDimensaoMatriz matriz1){
    printf("(Coluna) numero aleatorio sendo gerado...\n");
    matriz1.coluna=rand()%COLUNA;
    return matriz1.coluna;
}

int** criarMatriz(int linhamax, int colunamax){
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

int** criarMatrizKernel(){
    int **m;
    m=(int**) malloc(3 * sizeof(sizeof(int *)));
    for(int l=0; l<3;l++){
        m[l]=(int*)malloc(3 * sizeof(int));
    }
    if (m == NULL){
        printf("Erro ao alocar memoria!\n");
    }
    return m;
}

int escolhaKernel(){
    int var;
    printf("\nMatrizes para a convolucao:\n");
    printf("1 - realcar bordas (3x3):\n");
    printf("0 - para finalizar o programa\n");
    scanf("%i", &var);
    return var;
}

void escolhaValoresDentroMatriz(int linhamax, int colunamax, int **matriz){
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            matriz[l][c]=rand()%TAM;
        }
    }
}

void escreverValoresDentroMatriz(int linhamax, int colunamax, int **matriz){
    printf("MATRIZ:\n");
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            printf("%i\t", matriz[l][c]);
        }
        printf("\n");
    }
}

void processoConvolucaoeEscolhaKernel(int linhamax, int colunamax, int **matriz, int **matrizaux){
    switch(escolhaKernel()){
        case 1:
            kernelCaso1(linhamax, colunamax, matriz, matrizaux); // *passagem de parâmetro por valor e referência, elementos do ponteiro
            break;
        case 0:
            finalizarPrograma();
            break;
    }
}

void escolhaValoresDentroKernel(int **kernel){
    for(int l=0;l<3;l++){
        for(int c=0;c<3;c++){
            kernel[l][c]=rand()%2;
        }
    }
}


void kernelCaso1(int linhamax, int colunamax, int **matriz, int **matrizaux){
    int **kernel;
    kernel=criarMatrizKernel();
    escolhaValoresDentroKernel(kernel);
    for(int l=0;l<3;l++){
        for(int c=0;c<3;c++){
            printf("%i\t", kernel[l][c]);
        }
        printf("\n");
    }
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                printf("\t");
            }
            else{
                matrizaux[l][c]=((matriz[l-1][c-1]*kernel[0][0])+(matriz[l-1][c]*kernel[0][1])+(matriz[l-1][c+1]*kernel[0][2])+(matriz[l][c-1]*kernel[1][0])+(matriz[l][c]*kernel[1][1])+(matriz[l][c+1]*kernel[1][2])+(matriz[l+1][c-1]*kernel[2][0])+(matriz[l+1][c]*kernel[2][1])+(matriz[l+1][c+1]*kernel[2][2]));
                printf("%i\t", matrizaux[l][c]);
            }
        }
        printf("\n");
    }
}

void desalocaMatrizeMatrizaux(int linhamax, int **matriz, int **matrizaux){
    printf("Desalocando memoria\n");

    for(int l=0; l<linhamax;l++){
        free(matriz[l]);
    }
    free(matriz);

    for(int l=0; l<linhamax;l++){
        free(matrizaux[l]);
    }
    free(matrizaux);
}

void finalizarPrograma(){
    printf("PROGRAMA FINALIZADO\n");
}
