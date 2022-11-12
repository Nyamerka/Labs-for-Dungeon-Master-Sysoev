#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    long quality, number;
    long ost [9] = {-10000000000};
    scanf("%ld", &quality);
    for (int i = 0; i < quality; i++) {
        scanf("%ld", &number);
        for (int j = 0; j < 3; j++) {
            if (number > ost [((number % 3) * 3) + j]) {
                int k = j + 2;
                while (k != 4) {
                    ost [((number % 3) * 3) + (4 - k)] = 
                    ost [((number % 3) * 3) + (3 - k)];
                    k++;
                }
                ost [((number % 3) * 3) + j] = number;
                break;
            }
        }
    }
    printf("%f\n", fmax(fmax(ost [0] + ost [1] + ost [2], 
                             ost [3] + ost [4] + ost [5]), 
                        fmax(ost [6] + ost [7] + ost [8], 
                             ost [0] + ost [3] + ost [6])));
    return 0;
}