#include <iostream>

#define INF 2'100'000'000

using namespace std;

int arr[1001][3], n, ans = INF;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> arr[i][j];

    for(int s = 0; s < 3; s++) {
        int dp[1001][3];
        for(int i = 0; i < 3; i++) {
            if(i == s) dp[0][i] = arr[0][i];
            else dp[0][i] = INF;
        }

        for(int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2]; 
        }

        for(int i = 0; i < 3; i++) if(i != s) ans = min(ans, dp[n-1][i]);
    }

    cout << ans;
}