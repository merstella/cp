#include <stdio.h>
#include <string.h>

int main() {
    char s[2001], t[2001];
    fgets(s, 2001, stdin);
    fgets(t, 2001, stdin);

    // Remove trailing newline characters
    s[strcspn(s, "\n")] = 0;
    t[strcspn(t, "\n")] = 0;

    int len_s = strlen(s);
    int len_t = strlen(t);
    int found = 0;  

    for (int i = 0; i <= len_s - len_t; i++) {
        if (strncmp(s + i, t, len_t) == 0) {
            printf("%d ", i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("-1");
    }

    return 0;
}
