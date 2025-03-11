#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF 2'100'000'000

using namespace std;

int n, dp[200'001][4], a[200'001];

int main() {
  fastio;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  dp[1][0] = a[1]; dp[1][1] = dp[1][2] = dp[1][3] = 1;
  for(int i = 2; i <= n; i++) {
    dp[i][0] = dp[i-1][0] <= a[i] ? a[i] : INF;
    for(int j = 1; j <= 3; j++) {
      dp[i][j] = dp[i-1][j-1];
      if(dp[i-1][j] <= a[i]) dp[i][j] = min(dp[i][j], a[i]);
    }
  }

  int m = INF, idx = 0;
  for(int i = 0; i < 4; i++) if(m > dp[n][i]) m = dp[n][i], idx = i;
  if(m != INF) {
    cout << "YES\n" << idx << "\n";
    for(int i = n, j = idx; i >= 1 && j; i--) {
      if(dp[i-1][j] > a[i] || dp[i-1][j-1] < a[i]) {
        cout << i << ' ' << dp[i][j--] << '\n';
      }
    }
  } else cout << "NO";
}
