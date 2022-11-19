#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    char line[] ="";
    scanf("%[^\n]s", &line [0]);
    printf("%s\n", line);
    return 0;
}