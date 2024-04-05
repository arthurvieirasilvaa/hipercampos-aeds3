#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <getopt.h>
#include <stdint.h>
#include <time.h>
#include "tp.h"

int main(int argc, char *argv[]) {
    // Uso das funções getrusage e gettimeofday para medir o tempo gasto pela aplicação:
    struct rusage usage_inicio, usage_fim;  // Estruturas para a função getrusage.
    struct timeval tempo_inicio, tempo_fim; // Estruturas para a função gettimeofday.

    getrusage(RUSAGE_SELF, &usage_inicio);
    gettimeofday(&tempo_inicio, NULL);

    // Uso da primitiva getopt para analisar os parâmetros da linha de comando:
    int opt;
    char *input = NULL;
    char *output = NULL;

    while((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch(opt) {
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case '?':
                fprintf(stderr, "Opcao invalida: -%c", optopt);
                return 1;
            default:
                exit(1);
        }
    }

    if(input == NULL || output == NULL) {
        fprintf(stderr, "Forneca o arquivo de entrada usando o parametro -i e o de saida usando -o\n");
        exit(1);
    }

    // Declaração das variáveis que serão utilizadas na leitura do arquivo de entrada:
    int n = 0;
    ponto a, b;
    ponto *pnt = (ponto*) malloc(n * sizeof(ponto));

    LerPontos(input, &a, &b, &pnt, &n);
    InsertionSort(&pnt, &n);

    vetor *u = (vetor*) malloc(n * sizeof(vetor));
    vetor *v = (vetor*) malloc(n * sizeof(vetor));

    ProduzirVetores(&pnt, &a, &b, &u, &v, &n);

    int resultado = MaximodePontos(&u, &v, &n);
    printf("%d\n", resultado);

    SalvarOutput(output, resultado);

    getrusage(RUSAGE_SELF, &usage_fim);
    gettimeofday(&tempo_fim, NULL); 

    // Calcular o tempo de usuário:
    float usuario = (usage_fim.ru_utime.tv_sec - usage_inicio.ru_utime.tv_sec) + 1e-6* (usage_fim.ru_utime.tv_usec - usage_inicio.ru_utime.tv_usec);

    // Calcular o tempo de sistema:
    float sistema = (usage_fim.ru_stime.tv_sec - usage_inicio.ru_stime.tv_sec) + 1e-6* (usage_fim.ru_stime.tv_usec - usage_inicio.ru_stime.tv_usec);

    // Calcular o tempo decorrido no relógio:
    float tempo = (tempo_fim.tv_sec - tempo_inicio.tv_sec) +  1e-6 *(tempo_fim.tv_usec - tempo_inicio.tv_usec);

    printf("User: %0.6fs\n", usuario);
    printf("System: %0.6fs\n", sistema);
    printf("Time: %0.6fs\n", tempo);

    free(pnt);
    free(u);
    free(v);
    
    return 0;
}
