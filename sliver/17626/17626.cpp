#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[50'001];

int main() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) dp[i] = 5;
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= (int)sqrt(i); j++) {
      dp[i] = min(dp[i - j * j] + 1, dp[i]);
    }
  }

  cout << dp[n];
}