#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


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

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            printf("%d ", m[i][j]);
    }

    //int answer = solve(m, n);
    //printf("%d\n", answer);
    return 0;
}