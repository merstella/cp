#include<stdio.h>

long long C[50][50];

void tinhToHop() {
    for (int i = 0; i <= 49; i++) {
        C[i][0] = C[i][i] = 1;
        C[i][1] = C[i][i-1] = i;
        for (int j = 2; j < i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

int main() {
    tinhToHop();
    int k, n;
    scanf("%d%d", &k, &n);
    printf("%lld", C[n][k]);
    return 0;
}
