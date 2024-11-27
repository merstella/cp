#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n >= (1 << 16)) {
        puts("TOO BIG");
    }
    else {
        if (n == 0){
            printf("%d", 0);
            return 0;
        }
        int a[16]; int i = 0;
        while (n > 0) {
            a[i] = n % 2;
            n /= 2;
            ++i;
        }
        for (int j = i - 1; j >= 0; --j) {
            printf("%d", a[j]);
        }
    }
    return 0;
}