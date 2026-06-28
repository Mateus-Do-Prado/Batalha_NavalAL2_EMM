#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AGUA 0
#define AGUADESCONHECIDA 7
#define TAMANHO 8
#define NAVIO 1
#define NAVIOATINGIDO 2
#define TAMANHO_NAVIO 2  
#define QTD_NAVIOS 4 

typedef struct {
    int linha[TAMANHO_NAVIO];
    int coluna[TAMANHO_NAVIO];
    int partesAtingidas;
    int afundado;
} Navio;

int verificaSobreposicao(int **campo, int tamanho, int linha, int coluna) {
    if (linha < 0 || linha >= tamanho || coluna < 0 || coluna >= tamanho)
        return 1;

    return campo[linha][coluna] != AGUA;
}

void limpar_campo(int **campo, int tamanho){
    if(campo != NULL){
        for(int i = 0; i < tamanho; i++){
            free(campo[i]);
        }
        free(campo);
    }
}

int **AlocarMatriz(int tam){
    int **matriz = (int **)malloc(tam * sizeof(int *));

    if(matriz == NULL){
        printf("ERRO\n");
        return NULL;
    }

    for(int i = 0; i < tam; i++){
        matriz[i] = (int *)malloc(tam * sizeof(int));

        if(matriz[i] == NULL){
            for(int j = 0; j < i; j++){
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }

        for(int j = 0; j < tam; j++){
            matriz[i][j] = AGUA;
        }
    }