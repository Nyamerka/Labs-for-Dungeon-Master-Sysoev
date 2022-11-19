#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool checkPositive (int size, int array [size]) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array [i]);
        if (array [i] < 0) {
            return false;
        }
    }
    return true;
}

int main () {
    int size;
    scanf("%d", &size);
    int numbers [size];
    if (checkPositive(size, numbers)) {
        printf("Succes!\n");
    }
    else {
        printf("What a pitty! That's a fault\n");
    }
    return 0;
}