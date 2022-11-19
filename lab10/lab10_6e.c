#include <stdlib.h>
#include <stdio.h>

int main () {
    int mega = 2;
    for (int i = 0; i < 50; i ++) {
        mega *= 2;
    }
    printf("%d\n", mega);
    return 0;
}