#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 2000
#define MAX_LENGTH 128

int main() {
    int N;
    char strings[MAX_STRINGS][MAX_LENGTH];

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", &strings[i]);
    }

    for (int i = 0; i < N - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < N; ++j) {
            if (strcmp(strings[j], strings[min_idx]) < 0) {
                min_idx = j;
            }
        }    
        if (min_idx != i) {
            char temp[MAX_LENGTH];
            strcpy(temp, strings[i]);
            strcpy(strings[i], strings[min_idx]);
            strcpy(strings[min_idx], temp);
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
 
 