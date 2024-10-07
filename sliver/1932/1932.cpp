#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[501][501], dp[501][501];

// dp[i][j]: (0,0) -> (i,j)까지 가는 경로의 최댓값

int getDp(int depth, int idx) {
  if(depth == 0) return arr[0][0];
  if(dp[depth][idx] != -1) return dp[depth][idx];

  if(idx != 0 && idx != depth) dp[depth][idx] = max(getDp(depth - 1, idx), getDp(depth - 1, idx - 1));
  else {
    if(idx == 0) dp[depth][idx] = getDp(depth - 1, idx);
    else dp[depth][idx] = getDp(depth - 1, idx - 1);
  }
  
  dp[depth][idx] += arr[depth][idx];
  return dp[depth][idx];
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) ans = max(ans, getDp(n - 1, i));
  cout << ans;

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j <= i; j++) cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }
}