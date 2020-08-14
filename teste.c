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
void escreverValoresDentroKernel(int **kernel);
void processoConvolucaoeEscolhaKernel(int linhamax, int colunamax, int **matriz, int **matrizaux, int **kernel);
void escreverValoresMatrizAux(int linhamax, int colunamax, int **matrizaux);
void desalocaMatrizeMatrizaux(int linhamax, int **matriz, int **matrizaux, int **kernel);
void kernelCaso1(int linhamax, int colunamax, int **matriz, int **matrizaux, int **kernel);
int convolucaoCaso1(int l, int c, int **matriz, int **kernel);
void finalizarPrograma(); // *modularização(procedimento e de ação), prototipação

int main(){
    sDimensaoMatriz matriz1;

    int linhamax=escolhaLinhaMax(matriz1); // *uso do registro
    int colunamax=escolhaColunaMax(matriz1);

    int **matriz; // *uso de ponteiro dentro de outro ponteiro
    matriz=criarMatriz(linhamax, colunamax); //alocação dinâmica de memória

    int **matrizaux; 
    matrizaux=criarMatriz(linhamax, colunamax);

    int **kernel;
    kernel=criarMatrizKernel();

    escolhaValoresDentroMatriz(linhamax, colunamax, matriz); // *passagem de parâmetro por valor e referência
    escreverValoresDentroMatriz(linhamax, colunamax, matriz);

    escolhaValoresDentroKernel(kernel);
    escreverValoresDentroKernel(kernel); 
    
    processoConvolucaoeEscolhaKernel(linhamax, colunamax, matriz, matrizaux, kernel);
    desalocaMatrizeMatrizaux(linhamax, matriz, matrizaux, kernel);

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

void processoConvolucaoeEscolhaKernel(int linhamax, int colunamax, int **matriz, int **matrizaux, int **kernel){
    switch(escolhaKernel()){
        case 1:
            kernelCaso1(linhamax, colunamax, matriz, matrizaux, kernel); // *passagem de parâmetro por valor e referência, elementos do ponteiro
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

void escreverValoresDentroKernel(int **kernel){
    printf("KERNEL:\n");
    for(int l=0;l<3;l++){
        for(int c=0;c<3;c++){
            printf("%i\t", kernel[l][c]);
        }
        printf("\n");
    }
}

void kernelCaso1(int linhamax, int colunamax, int **matriz, int **matrizaux, int **kernel){
    for(int l=0;l<linhamax; l++){
        for(int c=0;c<colunamax; c++){
            if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                matrizaux[l][c]=matrizaux[l][c];
            }
            else{
                matrizaux[l][c]=convolucaoCaso1(l, c, matriz, kernel);
            }
        }  
    }
    escreverValoresMatrizAux(linhamax, colunamax, matrizaux);
}

int convolucaoCaso1(int l, int c, int **matriz, int **kernel){
    int matrizaux=0;
    int auxmatrizaux=0;
    l--; 
    c--;
    int aux=c;
    for(int lk=0;lk<3;lk++){
        for(int ck=0;ck<3;ck++){
            matrizaux = matriz[l][c] * kernel[lk][ck];
            auxmatrizaux=auxmatrizaux+matrizaux;
            c++;
        }
        c=aux;
        l++;
    }
    return auxmatrizaux;
}

void escreverValoresMatrizAux(int linhamax, int colunamax, int **matrizaux){
    printf("MATRIZ FILTRADA:\n");
    for(int l=0;l<linhamax;l++){
        for(int c=0;c<colunamax;c++){
            if(l==0 || c==0 || l==linhamax-1 || c==colunamax-1){
                printf("\t");
            }
            else{
                printf("%i\t", matrizaux[l][c]);
            }
        }
        printf("\n");
    }
}

void desalocaMatrizeMatrizaux(int linhamax, int **matriz, int **matrizaux, int **kernel){
    printf("Desalocando memoria: matriz original...\n");
    for(int l=0; l<linhamax;l++){
        free(matriz[l]);
    }
    free(matriz);
    printf("Desalocando memoria: matriz kernel...\n");
    for(int l=0; l<3;l++){
        free(kernel[l]);
    }
    free(kernel);
    printf("Desalocando memoria: matriz auxiliar...\n");
    for(int l=0; l<linhamax;l++){
        free(matrizaux[l]);
    }
    free(matrizaux);
}

void finalizarPrograma(){
    printf("PROGRAMA FINALIZADO\n");
}