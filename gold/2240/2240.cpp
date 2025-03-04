#include <iostream>

using namespace std;

int n, w, dp[1002][32], arr[1002];

int main() {
  cin >> n >> w;
  for(int i = 1; i <= n; i++) cin >> arr[i];

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= min(w, i); j++) {
      int new_dp = 0, loc = j % 2 == 0 ? 1 : 2;
      for(int k = 0; k <= j; k++) new_dp = max(new_dp, dp[i-1][k]);
      if(arr[i] == loc) new_dp++;
      dp[i][j] = new_dp;

      // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
    }

    // cout << "\n";
  }

  int ans = 0;
  for(int i = 0; i <= w; i++) ans = max(ans, dp[n][i]);

  cout << ans;
}