#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int getMatrix (int size, int matrix [size] [size]) {
    int max = 0, result = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix [i] [j]);
            if (matrix [i] [j] > max || (i == 0 && j == 0)) {
                max = matrix [i] [j];
                result = j;
            }
        }
    }
    return result;
}

void reverseColumn (int size, int matrix [size] [size], int column) {
    int tmp;
    for (int i = 0; i < size / 2; i++) {
        tmp = matrix [i] [column];
        matrix [i] [column] = matrix [size - 1 - i] [column];
        matrix [size - 1 - i] [column] = tmp;
    }
}

void printMatrix (int size, int matrix [size] [size], int column) {
    reverseColumn(size, matrix, column);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix [i] [j]);
        }
        printf("\n");
    }
}

int main() {
    int size, column;
    scanf("%d", &size);
    assert(size >= 1 && size <= 8);
    int matrix [size] [size];
    column = getMatrix(size, matrix);
    assert(column >= 0);
    printMatrix(size, matrix, column);

    return 0;
}