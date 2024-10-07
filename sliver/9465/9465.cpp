#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[2][100'001], dp[2][100'001];

int getDp(int c, int r) {
  if(c < 0) return 0;
  if(dp[r][c] != -1) return dp[r][c];

  dp[r][c] = max(getDp(c - 1, !r), getDp(c - 2, !r)) + arr[r][c];
  return dp[r][c];
}

void solve() {
  cin >> n;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  cout << max(getDp(n - 1, 0), getDp(n - 1 ,1)) << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}