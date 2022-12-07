#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int decrementMask (int number) {
    int n = abs(number), mask = 1, result = 0;
    if (n == 0) {
        return 1;
    }
    while (n > 0) {
        if (n % 2 == 0) {
            result += mask;
        }
        n /= 10;
        mask *= 10;
    }
    return result;
}

int main () {
    assert(decrementMask(0) == 1);
    assert(decrementMask(111) == 0);
    assert(decrementMask(12) == 1);
    assert(decrementMask(222) == 111);
    assert(decrementMask(2121) == 1010);
    assert(decrementMask(202020) == 111111);
    assert(decrementMask(-1222) == 111);
    assert(decrementMask(-0) == 1);
    int number;
    scanf("%d", &number);
    (number >= 0) ? printf("%d\n", number - decrementMask(number)):
                    printf("%d\n", number + decrementMask(number));
    return 0;
}