#include <stdio.h>

int n, dp[50][2];

void fibo(int i) {
    if(i == n) {
        return;
    }
    dp[i + 1][0] = dp[i - 1][0] + dp[i][0];
    dp[i + 1][1] = dp[i - 1][1] + dp[i][1];
    fibo(i + 1);
}

int main() {
    int t, big = 0;;
    dp[0][0] = 1;
    dp[1][1] = 1;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n >= 2 && n > big) {
            big = n;
            fibo(1);
        }
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }
}