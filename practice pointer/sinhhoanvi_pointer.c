#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    char str[50];
    scanf("%s", str);

    char* p = str;
    int n = strlen(str);
    while (1) {
        printf("%s\n", str);
        int i = n - 2;
        while (i >= 0 && *(p + i) >= *(p + i + 1)) {
            --i;
        }
        if (i < 0) break;

        int pos = -1;
        for (int j = i + 1; j < n; ++j) {
            if (*(p + j) > *(p + i)) {
                pos = j;
            }
        }

        swap(p + i, p + pos);

        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (*(p + j) > *(p + k)) {
                    swap(p + j, p + k);
                }
            }
        }
    }

    return 0;
}
