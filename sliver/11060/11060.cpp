#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001], dp[1001][102];

int get_dp(int idx, int w) {
  if(dp[idx][w] != -1) return dp[idx][w];
  if(
    dp[idx][w] == 2'100'000'000 ||
    w == 0 ||
    idx + w >= n
  ) return -1;
  if(idx + w == n - 1) return 1;
  
  int new_dp = 2'100'000'000;
  for(int i = 1; i <= arr[idx + w]; i++) {
    int v = get_dp(idx + w, i);
    if(v != -1) new_dp = min(new_dp, v);
  }

  dp[idx][w] = new_dp;
  
  if(new_dp != 2'100'000'000) {
    dp[idx][w]++;
    return new_dp + 1;
  }
  else return -1;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    for(int j = 0; j <= 100; j++) dp[i][j] = -1;
  }

  if(n == 1) {
    cout << arr[0];
    return 0;
  }

  int ans = 2'100'000'000;
  for(int i = 1; i <= arr[0]; i++) {
    int v = get_dp(0, i);
    if(v != -1) ans = min(v, ans);
  }

  if(ans != 2'100'000'000) cout << ans;
  else cout << -1;
  // cout << endl;
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < 10; j++) cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }
}