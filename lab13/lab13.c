#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

bool is_NewWord (char symbol) {
    return (symbol == '\n' || symbol == '\t' || symbol == ',' || symbol == ' ') ? true : false;
}

bool englishSetsAreEqual (int set1 [26], int set2 [26]) {
    for (int i = 0; i < 26; i++) {
        if (set1 [i] != set2 [i]) {
            return false;
        }
    }
    return true;
}

void setToSet_clearSecondSet (int set1 [26], int set2 [26]) {
    for (int i = 0; i < 26; i++) {
        set1 [i] = set2 [i];
        set2 [i] = 0;
    }
}

int main () {
    char letter;
    int wordSet1 [26] = {0}, wordSet2 [26] = {0};
    bool flag = true;
    assert(is_NewWord('\n') == true);
    assert(is_NewWord('\t') == true);
    assert(is_NewWord('a') == false);
    while ((letter = getchar()) != EOF) {
        if (is_NewWord(letter)) {
            if (flag) {
                flag = false;
                continue;
            }
            else {
                if (englishSetsAreEqual(wordSet1, wordSet2)) {
                    printf("Yes\n");
                    return 0;
                }
                setToSet_clearSecondSet(wordSet1, wordSet2);
                continue;
            }
        }
        letter = tolower(letter);
        if (flag) {
            wordSet1 [letter - 'a'] = 1;
            continue;
        }
        wordSet2 [letter - 'a'] = 1;
    }
    printf("No\n");
    return 0;
}
