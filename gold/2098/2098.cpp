#include <iostream>
#include <cstring>

#define INF 2'100'000'000/2

using namespace std;

int n, arr[16][16], dp[16][1 << 16];

int get_dp(int idx, int mask) {
  if(mask == (1 << n) - 1) {
    if(arr[idx][0] != 0) return arr[idx][0];
    else return INF;
  }

  if(dp[idx][mask] != -1) return dp[idx][mask];

  dp[idx][mask] = INF;
  for(int i = 0; i < n; i++) {
    if(
      arr[idx][i] != 0 &&
      (mask & (1 << i)) != 1 << i
    ) {
      dp[idx][mask] = min(dp[idx][mask], get_dp(i, mask | 1<<i) + arr[idx][i]);
    }
  }

  return dp[idx][mask];
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << get_dp(0, 1);
}