#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef enum {
    NewWord,
    Rubbish,
    Number
} State; 

bool is_NewWord (char symbol) {
    if (symbol == '\n' || symbol == '\t' || symbol == ',' || symbol == ' ') {
        return true;
    }
    return false;
}

bool is_Rubbish (char symbol) {
    if ((symbol < '0' || symbol > '9') && is_NewWord(symbol) == false) {
        return true;
    }
    return false;
}

bool is_PlusMinus (char symbol) {
    if (symbol == '+' || symbol == '-') {
        return true;
    }
    return false;
}

bool is_Number (char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return true;
    }
    return false;
}
void printArray (int n, char array [n]) {
    for (int i = 0; i < n; i++) {
        printf("%c", array [i]);
    }
    printf(" ");
}

int main () {
    assert(is_Rubbish('a') == true);
    assert(is_Rubbish('@') == true);
    assert(is_Rubbish('0') == false);
    assert(is_NewWord('\n') == true);
    assert(is_NewWord('\t') == true);
    assert(is_NewWord('i') == false);
    assert(is_PlusMinus('+') == true);
    assert(is_PlusMinus('a') == false);
    assert(is_Number('0') == true);
    assert(is_Number('a') == false);
    State state = NewWord;
    char symbol, *number;
    number = (char *) malloc(1);
    int i = 0, summ = 0, firstZero = 0;
    bool flag = true;
    while ((symbol = getchar()) != EOF) {
        switch (state) {
            case NewWord:
                if (is_PlusMinus(symbol)) {
                    state = Number;
                    break;
                }
                if (is_Rubbish(symbol)) {
                    state = Rubbish;
                    break;
                }
                if (is_Number(symbol)) {
                    state = Number;
                    firstZero = symbol - '0';
                    if (firstZero == 0) {
                        break;
                    }
                    else {
                        flag = false;
                    }
                    number [i] = symbol;
                    i++;
                    number = (char *) realloc(number, i + 1);
                    break;
                }
            case Rubbish:
                if (is_NewWord(symbol)) {
                    state = NewWord;
                }
                break;
            case Number:
                if (is_Number(symbol)) {
                    if (flag) {
                        firstZero = symbol - '0';
                        if (firstZero == 0) {
                            flag = true;
                            break;
                        }
                        else {
                            flag = false;
                        }
                    }
                    number [i] = symbol;
                    if(i % 2 != 0) {
                        summ += symbol - '0';
                    }
                    i++;
                    number = (char *) realloc(number, i + 1);
                    break;
                }
                if (is_NewWord(symbol)) {
                    state = NewWord;
                    printArray(i, number);
                    printf("%d\n", summ);
                }
                else {
                    state = Rubbish;
                }
                i = 0;
                summ = 0;
                flag = true;
                firstZero = 0;
                break;
        }
    }
    return 0;
}
