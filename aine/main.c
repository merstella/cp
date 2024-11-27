#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1001], t[1001];
    scanf("%s", s);
    getchar();
    char x[1001];
    scanf("%s", x);

    char* p = strstr(s, x);
    if (p == NULL) {
        puts("-1");
    } else {
        printf("Tim thay tai vi tri: %d", p - s + 1);
    }
    return 0;
}

