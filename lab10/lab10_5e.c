#include <stdlib.h>
#include <stdio.h>

void inputArray (int size, int array [size]) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array [i]);
    }
}

void outputArray (int size, int array [size]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array [i]);
    }
    printf("\n");
}

int main () {
    int size;
    int array [size];
    inputArray(size , array);
    outputArray(size, array);
    return 0;
}