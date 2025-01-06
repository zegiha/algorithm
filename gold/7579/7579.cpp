#include <stdio.h>
// BOJ 7579

int N, M;
int m[100], c[100];
int dp[100][10001];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &m[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (i == 0) {
                if (j >= c[i]) {
                    dp[i][j] = m[i];
                }
            } else {
                if (j >= c[i]) {
                    dp[i][j] = dp[i - 1][j - c[i]] + m[i];
                }
                dp[i][j] = dp[i][j] > dp[i - 1][j] ? dp[i][j] : dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= 10000; i++) {
        if (dp[N - 1][i] >= M) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}