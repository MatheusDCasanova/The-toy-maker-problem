#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node
{
   int value;
   int toy_line_matrix;
   int toy_column_matrix;
   int toy_id_max;
   int toy_id_min;
} ;

typedef struct Node * p_node;

void Intercala(int *vetor, int inicio, int meio, int fim){
    int *aux = malloc(sizeof(node)*(fim-inicio+1));

    for (int i = inicio; i <= meio; i++){
        aux[i] = vetor[i];
    }
    for (int j = meio + 1; j <= fim; j++){
        aux[fim + meio - j] = vetor[j];
    }

    i = inicio;
    j = fim;

    for (int k = inicio; k <= fim; k++){
        if (aux[i] <= aux[j]){
            vetor[k] = aux[i];
            i++;
        }
        else{
            vetor[k] = aux[j];
            j--;
        }
    }
}


void MergeSort(int *vetor, int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim) / 2;
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio + 1, fim);
        Intercala(vetor, inicio, meio, fim);
    }
}


/*
 * Complete a funcao solve para resolver o problema.
 * m é uma matriz n x n, em que m[i][j] contem o valor
 * do j-esimo item dentre os itens do tipo i.
 * Fique a vontade para representar os itens de outra forma
 * e escrever funcoes e estruturas auxiliares.
 */

/*
    1) ordenar cada linha (brinquedo) da matriz m (n * nlogn)
    2) pegar o primeiro elemento de cada linha da matriz 
    e criar um heap de mínimo e um heap de máximo com esses n elementos
    3) verificar a diferença entre o mínimo e o máximo
    (diferença entre a raíz do heap mínimo e a raíz do heap máximo)
    4) se a diferença for menor que a diferença anterior, atualizar a diferença
    5) pego o id (linha da matriz) do brinquedo da raiz do min heap e do max heap
    6) 


*/

int solve(int **m, int n) {

    p_node min_heap = malloc(sizeof(Node)*n);
    p_node max_heap = malloc(sizeof(Node)*n);

    int min_diff = INT_MAX;


    return 0;
}

int main() {

    int n;
    scanf("%d", &n);

    int **m = malloc(n * sizeof(int *));
    for(int i = 0; i < n; ++i)
        m[i] = malloc(n * sizeof(int));

    for(int i = 0; i < n; ++i) {
        long long int a, b, c;
        scanf("%d %lld %lld %lld", &m[i][0], &a, &b, &c);
        for(int j = 1; j < n; ++j)
            m[i][j] = (m[i][j-1] * a + b) % c;
    }

    int answer = solve(m, n);
    printf("%d\n", answer);
    return 0;
}