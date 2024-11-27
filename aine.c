#include <stdio.h>

bool isMatching(char* text, char* pattern) {
    if (*pattern == '\0' && *text == '\0') {
        return true;
    }

    if (*pattern == '\0') {
        return false;
    }

    while (*text != 0 && *pattern != '\0') {
        if (*pattern == '?') {
            text++;
            pattern++;
        }
        else {
            if (*text == *pattern) {
                text++;
                pattern++;
            } 
            else {
                return false;
            }
        }
    }
}

int main() {
    cout << isMatching("A?", "?A");
}