#include <stdlib.h>
#include <stdio.h>

int main () {
    long long mega = 2;
    for (int i = 0; i < 50; i ++) {
        mega *= 2;
    }
    printf("%lld\n", mega);
    return 0;
}