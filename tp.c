#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

// Função utilizada para leitura do arquivo de entrada:

void LerPontos(char *input, ponto *a, ponto *b, ponto **pnt, int *n) {
    FILE *entrada;
    entrada = fopen(input, "r");

    if(entrada == NULL) {
        printf("Arquivo não encontrado!\n");
        exit(1);
    }

    fscanf(entrada, "%d %d %d\n", &(*n), &a->x, &b->x);
    a->y = 0;
    b->y = 0;

    // Verificando se a quantidade de pontos está no intervalo 1 <= N <= 100:

    if(*n < 1 || *n > 100) {
        exit(1);
    }

    // Verificando se Xa é menor do que Xb, se Xb <= 10^4 
    // e se Xa e Xb são maiores do que 0:

    if(a->x >= b->x || b->x > 10000 || a->x <= 0 || b->x <= 0) {
        exit(1);
    }

    // Após ler o valor de n, faz-se um realloc() da variável pnt para
    // alocar um espaço de memória suficiente para armazenar os n pontos: 

    *pnt = (ponto*) realloc(*pnt, *n * sizeof(ponto));

    if(*pnt == NULL) {
        printf("A memoria nao foi alocada corretamente!\n");
        exit(1);
    }

    // Lendo as coordenadas dos n pontos:

    for(int i = 0; i < *n; i++) {
        fscanf(entrada, "%d %d", &(*pnt)[i].x, &(*pnt)[i].y);

        // Verificando se o ponto lido está dentro ou fora do conjunto P:
        if((*pnt)[i].x <= 0 || (*pnt)[i].y <= 0 || (*pnt)[i].y > 10000) {
            exit(1);
        }
    }
    fclose(entrada);
}

/*
    Algoritmo de ordenção InsertionSort utilizado para ordenar as coordenadas
    y dos pontos em ordem crescente. Além disso, há uma verificação no while 
    da função na qual faz a seguinte análise: se houverem coordenadas y iguais, então 
    haverá também uma ordenação das coordenadas x desses pontos em ordem crescente: 
*/

void InsertionSort(ponto **pnt, int *n) {
    int i, j;
    ponto *aux = (ponto*) malloc(sizeof(ponto));

    if(aux == NULL) {
        printf("A memoria nao foi alocada corretamente!\n");
        exit(1);
    }
    for(i = 1; i < *n; i++) {
        *aux = (*pnt)[i];
        j = i - 1;
        while((j >= 0 && ((*aux).y < (*pnt)[j].y)) || ((*aux).y == (*pnt)[j].y && (*aux).x < (*pnt)[j].x)) {
            (*pnt)[j+1] = (*pnt)[j];
            j--;
        }
        (*pnt)[j+1] = *aux;
    }
    free(aux);
}

/*
    Função utilizada para criar os 2 vetores referentes a um ponto C do conjunto P de pontos. Os seguintes vetores serão produzidos: AC = u e BC = v:
*/

void ProduzirVetores(ponto **pnt, ponto *a, ponto *b, vetor **u, vetor **v, int *n) {
    for(int i = 0; i < *n; i++) {
        (*u)[i].i = (*pnt)[i].x - (*a).x;
        (*u)[i].j = (*pnt)[i].y - (*a).y;

        (*v)[i].i = (*pnt)[i].x - (*b).x;
        (*v)[i].j = (*pnt)[i].y - (*b).y;
    }
}

/* 
    Função utilizada para obter o número máximo de pontos que podem
    ser conectados com interseção apenas nas âncoras: 
*/

int MaximodePontos(vetor **u, vetor **v, int *n) {
    // pv1 e pv2 são utilizadas para armazenar os valores do produto vetorial
    // entre u1 x u2 e v1 x v2:
    int pv1, pv2;

    // Array utilizado para armazenar o número de conexões feito por cada ponto:
    int *conexoes = (int*) malloc((*n) * sizeof(int));

    int maior = 0;
    for(int i = 0; i < *n; i++) {
        // Cada ponto pode fazer pelo menos 1 conexão:
        conexoes[i] = 1;
        // Variável utilizada para armazenar o número máximo de conexões feito por
        // um ponto abaixo do ponto na posição i:
        int maxconexoes = 0;
        for(int j = i - 1; j >= 0; j--) {
            pv1 = ((*u)[i].i * (*u)[j].j) - ((*u)[j].i * (*u)[i].j); // pv1 = u1 x u2
            pv2 = ((*v)[i].i * (*v)[j].j) - ((*v)[j].i * (*v)[i].j); // pv2 = v1 x v2
            if(pv1 < 0 && pv2 > 0) {
                if(conexoes[j] > maxconexoes) {
                    maxconexoes = conexoes[j];
                }
            }
        }
        // O número de conexões do ponto na posição i será 1 (o mínimo de conexões que
        // o próprio ponto faz) acrescido do maior número de conexões feito por um ponto j:
        conexoes[i] += maxconexoes;
        if(conexoes[i] > maior) {
            // A resposta será o maior número de conexões feitas por um certo ponto
            // na posição i:
            maior = conexoes[i]; 
        }
    }

    free(conexoes);
    return maior;
}

/* 
    Função utilizada para criar um arquivo de saída output.txt com o resultado 
    obtido na função MaximodePontos:
*/

void SalvarOutput(char *output, int resultado) {
    FILE *saida;
    saida = fopen(output, "w");

    if(saida == NULL) {
        printf("Houve um erro ao criar o arquivo de saída!\n");
        exit(1);
    }
    fprintf(saida, "%d\n", resultado);
    fclose(saida);
}