#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Brinquedo{
    int value;
    int tipo;
} Brinquedo;


typedef Brinquedo * p_brinquedo;

void merge(p_brinquedo arr, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    p_brinquedo L = malloc(n1 * sizeof(Brinquedo)), M = malloc(n2 * sizeof(Brinquedo));

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i].value <= M[j].value) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}


void mergeSort(p_brinquedo arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
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
    1) pegar cada elemento da matriz e colocar em um vetor de brinquedos com suas propriedades
    2) ordenar o vetor de nós
    3) inicializar i e j como 0


*/

int solve(int **m, int n) {

    if (n == 1){
        return 0; 
    }

    p_brinquedo brinquedos = malloc(sizeof(Brinquedo) * (n * n)); //vetor com todos os brinquedos
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            brinquedos[k].value = m[i][j];
            brinquedos[k].tipo = i;
            k++;
        }
    }


    mergeSort(brinquedos, 0, (n*n)-1);

    int * contador_de_tipo = malloc(sizeof(int) * n); //vetor que conta quantos brinquedos de cada tipo existem na iteração atual
    
    for (int i = 0; i < n; i++){
        contador_de_tipo[i] = 0; //inicializar com 0
    }

    int brinquedos_diferentes = 0; //conta quantos brinquedos de tipos diferentes tenho englobados atualmente

    int min_diff = INT_MAX;

    int j = 0;
    int i = 0;

    contador_de_tipo[brinquedos[i].tipo]++;
    brinquedos_diferentes++;

    while (j < (n*n)-1){
        while(brinquedos_diferentes < n && j < (n*n) - 1){
            j++; 
            contador_de_tipo[brinquedos[j].tipo]++;
            if (contador_de_tipo[brinquedos[j].tipo] == 1){
                //esse tipo n estava antes dessa iteração
                brinquedos_diferentes++;
            }
        }
        //se sai do loop, tenho n brinquedos na minha solucao atual
        // maior valor esta em brinquedos[j].value e menor em brinquedos[i].value
        if (brinquedos_diferentes == n){
            if ((brinquedos[j].value - brinquedos[i].value) < min_diff){
                min_diff = (brinquedos[j].value - brinquedos[i].value);
            }
            contador_de_tipo[brinquedos[i].tipo]--;
            if (contador_de_tipo[brinquedos[i].tipo] == 0)
            {
                brinquedos_diferentes--;
            }
                
            i++;
        }
    }

    return min_diff;
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

/*
3
1 1 4 10
2 1 9 14
4 2 5 23
*/