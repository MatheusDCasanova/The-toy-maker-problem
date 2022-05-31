#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Complete a funcao solve para resolver o problema.
 * m é uma matriz n x n, em que m[i][j] contem o valor
 * do j-esimo item dentre os itens do tipo i.
 * Fique a vontade para representar os itens de outra forma
 * e escrever funcoes e estruturas auxiliares.
 */
int solve(int **m, int n) {

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