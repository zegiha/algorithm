#include <iostream>

using namespace std;

int arr[100'001][3], dp[100'001][3], n;
const int dy[] = {-1, -1, -1, 0}, dx[] = {-1, 0, 1, -1};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < 3;
}

int get_dp(int i, int j) {
  if(!is_area(i, j) || (i == 0 && j == 0)) return 2'100'000'000;
  if(dp[i][j] != -1) return dp[i][j];

  int new_dp = 2'100'000'000;
  for(int d = 0; d < 4; d++) {
    new_dp = min(get_dp(i + dy[d], j + dx[d]), new_dp);
  }

  if(new_dp == 2'100'000'000) new_dp = 0;
  return dp[i][j] = new_dp + arr[i][j];
}

int main() {
  int cnt = 1;
  while(true) {
    cin >> n; if(n == 0) break;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < 3; j++) {
        cin >> arr[i][j];
        dp[i][j] = -1;
      }
    }

    cout << cnt++ << ". " << get_dp(n - 1, 1) << '\n';
  }
}