#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct 
{
   int value;
   int tipo;
} Brinquedo;

typedef Brinquedo * p_brinquedo;

void Intercala(p_brinquedo vetor, int inicio, int meio, int fim){
    p_brinquedo aux = malloc(sizeof(Brinquedo)*(fim-inicio+1));

    for (int i = inicio; i <= meio; i++){
        aux[i] = vetor[i];
    }
    for (int j = meio + 1; j <= fim; j++){
        aux[fim + meio - j] = vetor[j];
    }

    int i = inicio;
    int j = fim;

    for (int k = inicio; k <= fim; k++){
        if (aux[i].value <= aux[j].value){
            vetor[k] = aux[i];
            i++;
        }
        else{
            vetor[k] = aux[j];
            j--;
        }
    }
}


void MergeSort(p_brinquedo vetor, int inicio, int fim){
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
    1) pegar cada elemento da matriz e colocar em um vetor de brinquedos com suas propriedades
    2) ordenar o vetor de nós
    3) inicializar i e j como 0


*/

int solve(int **m, int n) {

    p_brinquedo brinquedos = malloc(sizeof(Brinquedo) * n * n); //vetor com todos os brinquedos
    int k = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            brinquedos[k].value = m[i][j];
            brinquedos[k].tipo = i;
            k++;
        }
    }

    MergeSort(brinquedos, 0, (n*n)-1);

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

    while (j < n-1){
        while(brinquedos_diferentes < n && j < (n-1)){
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

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", m[i][j]);
        }
    }

    int answer = solve(m, n);
    printf("%d\n", answer);
    return 0;
}
/*
Caso teste
3
1 1 4 10
2 1 9 14
4 2 5 23
*/