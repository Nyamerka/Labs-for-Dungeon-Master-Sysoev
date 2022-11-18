#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

double fabs (double x) {
    if (x < 0) {
        return x * (-1);
    }
    return x;
}

double sqrt (double number) {
    double result = 1;
    double root;
    for(; ;) {
        root = (result + number / result) / 2;
        if (fabs (result - root) < 1e-10) {
            break;
        }
        result = root;
    }
    return result;
}

bool checkIntersection (int x1, int y1) {
    double distance1, distance2;
    distance1 = sqrt(((-10-x1) * (-10-x1)) + ((-10-y1) * (-10-y1)));
    distance2 = sqrt(((-20-x1) * (-20-x1)) + ((-20-y1) * (-20-y1)));
    if (distance1 <= 10 && distance2 <= 10) {
        return true;
    }
    return false;
}

int max (int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}

int min (int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

int main () {
    int i = 13, j = -9, l = -4, previous_i, previous_j, previous_l;
    for (int k = 0; k < 50; k++) {
        if (checkIntersection(i, j)) {
            printf ("Success! Time: %d\n", k);
            return 0;
        }
        previous_i = i; previous_j = j; previous_l = l;
        i = ((previous_i + previous_j) % 30) / (abs(previous_l) % 5 + 1) +
            ((previous_i + previous_l) % 30) / (abs(previous_j) % 5 + 1);
        j = max(k * previous_i, (k + 1) * previous_j) % 25 -
            abs(previous_j - previous_l) / 10;
        l = abs(previous_j - previous_l) / 10 + 
            min((previous_i + previous_l) % 20, (previous_j * k) % 20) - 10;
    }
    printf("What a pitty! That's a miss...\n");
    printf("Constant i: %d\n", previous_i);
    printf("Constant j: %d\n", previous_j);
    printf("Constant l: %d\n", previous_l);
    return 0;
}
