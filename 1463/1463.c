#include <stdio.h>

// 9 = 3 * 3 * 3
// 10 = 2 * 5
int dp[1000001];

int min (int a, int b){
    if(a < b) return a;
    else return b;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        // printf("%d : %d\n", i, dp[i]);
    }

    printf("%d", dp[n]);
    return 0;
}