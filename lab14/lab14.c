#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void igetMatrix (int n, int matrix [n] [n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix [i] [j]);
        }
    }
}

void iprintMatrix (int n, int matrix [n] [n]) {
    int step = 1, i = n - 1, j = 0, k = 1, z = 0;
    for (k = 1; k <= n; k++) {
        for (z = 0; z < k; z++) {
            printf("%d ", matrix [i] [j]);
            i += step;
            j += step;
        }
        step *= -1;
        if (step < 0) {
            i = n - 1;
            j = k;
        }
        else {
            i = n - k - 1;
            j = 0;
        }
    }
    for (k = n - 1; k > 0; k--) {
        if (step < 0) {
            i = k - 1;
            j = n - 1;
        }
        else {
            i = 0;
            j = n - k;
        }
        for (z = 0; z < k; z++) {
            printf("%d ", matrix [i] [j]);
            i += step;
            j += step;
        }
        step *= -1;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    assert(n > 0);
    int matrix [n] [n];
    igetMatrix(n, matrix);
    iprintMatrix(n, matrix);
    
    return 0;
}