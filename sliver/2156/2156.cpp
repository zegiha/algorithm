#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[10'001], dp[10'001][4];

int getDp(int idx, int st) {
  if(idx <= -1) return 0;
  if(dp[idx][st] != -1) return dp[idx][st];

  switch (st)
  {
  case 0:
    dp[idx][st] = getDp(idx - 1, 1) + arr[idx];
    break;
  case 1:
    dp[idx][st] = max(getDp(idx - 1, 2), getDp(idx - 1, 3)) + arr[idx];
    break;
  case 2:
    dp[idx][st] = max(getDp(idx - 1, 0), getDp(idx - 1, 1));
    break;
  case 3:
    dp[idx][st] = max(getDp(idx - 1, 2), getDp(idx - 1, 3));
  }

  return dp[idx][st];
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    for(int t = 0; t < 4; t++) dp[i][t] = -1;
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max({ans, getDp(i, 0), getDp(i, 1), getDp(i, 2), getDp(i, 3)});
  }

  cout << ans;
}