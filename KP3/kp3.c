#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <assert.h> 

int main () {
    int n, iterationsCounter = 1;
    long double Taylor, fuction, left = 0.0, right = 0.5, x = left, machineEpsilon = 1.0;
    while (1.0L + machineEpsilon > 1.0L) {
        machineEpsilon /= 2.0L;
    }
    printf("Machine epsilon for long double is %.16Le\n", machineEpsilon);
    printf("Write n: ");
    scanf("%d", &n);
    assert(n >= 0);
    printf("Your n is %d\n", n);
    printf("Table of values for Taylor's Formula and f(x) = ln((1 + x) / (1 - x))\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("|    x   |        Taylor        |          f(x)        | iterations |\n");
    printf("|-------------------------------------------------------------------|\n");
    for (int i = 1; i <= n + 1; i++) {
        Taylor = 2 * x;
        fuction = logl((1 + x) / (1 - x));
        iterationsCounter = 1;
        while (fabsl(Taylor - fuction) > machineEpsilon && iterationsCounter <= 100) {
            Taylor += 2 * ((powl(x, (iterationsCounter * 2) + 1)) / ((iterationsCounter * 2) + 1));
            iterationsCounter++;
        }
        iterationsCounter--;
        if (iterationsCounter >= 0 && iterationsCounter <=9) {
            printf("| %.4Lf | %.18Lf | %.18Lf |     %d      |\n", x, Taylor, fuction, iterationsCounter);
        }
        if (iterationsCounter >= 10 && iterationsCounter <= 99) {
            printf("| %.4Lf | %.18Lf | %.18Lf |     %d     |\n", x, Taylor, fuction, iterationsCounter);
        }
        if (iterationsCounter == 100) {
            printf("| %.4Lf | %.18Lf | %.18Lf |     %d    |\n", x, Taylor, fuction, iterationsCounter);
        }
        printf("|-------------------------------------------------------------------|\n");
        x += (right - left) / n;
    }

    return 0;
}
