#include <iostream>
#define MOD 1'000'000'000

using namespace std;

int n, dp[101][10][1024];

int getNewBit(int prev, int add) {
  return prev | (1 << add);
}

int main() {
  cin >> n;

  int newBit;

  for(int i = 1; i <= 9; i++) {
    dp[1][i][getNewBit(0, i)] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= 9; j++) {
      for(int k = 0; k < 1024; k++) {
        newBit = getNewBit(k, j);

        if(j == 0) {
          dp[i][j][newBit] = (dp[i][j][newBit] + dp[i-1][j+1][k]) % MOD;
        } else if(j == 9) {
          dp[i][j][newBit] = (dp[i][j][newBit] + dp[i-1][j-1][k]) % MOD;
        } else {
          dp[i][j][newBit] = (dp[i][j][newBit] + dp[i-1][j+1][k] + dp[i-1][j-1][k]) % MOD;
        }
      }
    }
  }

  int ans = 0;
  for(int j = 0; j <= 9; j++) {
    ans = (ans + dp[n][j][1023]) % MOD;
  }

  cout << ans;
}