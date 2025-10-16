#include <iostream>

using namespace std;
using pii = pair <int, int>;

int dp[102][50'002];
pii arr[101];

void solve(int n) {
  int total = 0;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i].first >> arr[i].second;
    total += arr[i].first * arr[i].second;
    for(int j = 0; j < 50'002; j++) dp[i][j] = 0;
  }

  if(total % 2 != 0) {
    cout << 0 << '\n';
    return;
  }

  dp[0][0] = 1;

  for(int i = 1; i <= n; i++) {
    for(int j = 50'000; j >= 0; j--) {
      if(dp[i - 1][j] != 1) continue;
      dp[i][j] = 1;
      for(int t = 1; t <= arr[i].second; t++) {
        if(j + arr[i].first * t < 50'001) {
          dp[i][j + arr[i].first * t] = 1;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(dp[i][total / 2]) {
      cout << 1 << '\n';
      return;
    }
  }
  cout << 0 << '\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin >> n) {
    solve(n);
  }
}