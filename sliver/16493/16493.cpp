#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[20][2];
int dp[20][200];

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> arr[i][0] >> arr[i][1];
    for(int j = 0; j < n; j++) dp[i][j] = -1;
  }

  int ans = 0;

  dp[0][0] = 0;
  dp[0][arr[0][0]] = arr[0][1];
  for(int i = 1; i < m; i++) {
    dp[i][0] = 0;
    dp[i][arr[i][0]] = max(dp[i - 1][arr[i][0]], arr[i][1]);
    cout << dp[i][arr[i][0]] << endl;
    if(arr[i][0] <= n && dp[i][arr[i][0]] > ans)  ans = dp[i][arr[i][0]];
    for(int j = 1; j < n; j++) {
      if(dp[i - 1][j] != -1) {
        dp[i][j + arr[i][0]] = max(dp[i][j + arr[i][0]], dp[i - 1][j] + arr[i][1]);
        if(j + arr[i][0] <= n && dp[i][j + arr[i][0]] > ans) ans = dp[i][j + arr[i][0]];
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      }
    }
    cout << dp[i][arr[i][0]] << ' ' << arr[i][0] << endl;
  }

  cout << ans;

  cout << endl;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) cout << dp[i][j] << ' ';
    cout << endl;
  }
}