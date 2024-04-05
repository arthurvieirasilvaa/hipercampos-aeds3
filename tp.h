//Estrutura usada para armazenar as coordenadas x e y dos n pontos fornecidos:
typedef struct Ponto {
    int x; 
    int y;
}ponto;

//Estrutura usada para armazenar os dois vetores de cada um dos n pontos:  
typedef struct Vetor {
    int i; // Representa o x do ponto.
    int j; // Representa o y do ponto.
}vetor;
 
void LerPontos(char*, ponto*, ponto*, ponto**, int*);

void InsertionSort(ponto **pnt, int *n);

void ProduzirVetores(ponto**, ponto*, ponto*, vetor**, vetor**, int*);

int MaximodePontos(vetor**, vetor**, int*);

void SalvarOutput(char*, int);
