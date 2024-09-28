#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[301][2], arr[301];

int getDp(int n, int j) {
  if(n <= 0) return 0;
  if(dp[n][j] != -1) return dp[n][j];
  if(j == 0) dp[n][j] = max(getDp(n - 2, 0), getDp(n - 2, 1)) + arr[n - 1];
  else dp[n][j] = getDp(n - 1, 0) + arr[n - 1];
  return dp[n][j];
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    dp[i + 1][0] = -1;
    dp[i + 1][1] = -1;
  }
  cout << max(getDp(n, 0), getDp(n, 1));
}