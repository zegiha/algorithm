#include <iostream>
#include <vector>

using namespace std;

int n, k;
int dp[31][31];

int getDp(int r, int c) {
  if(dp[r][c] != -1) return dp[r][c];
  if(r == c || c == 0) {
    dp[r][c] = 1;
    return 1;
  }

  dp[r][c] = getDp(r - 1, c - 1) + getDp(r - 1, c);
  return dp[r][c];
}

int main() {
  cin >> n >> k;
  for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = -1;
  dp[0][0] = 1;
  dp[1][0] = 1; dp[1][1] = 1;
  cout << getDp(n - 1, k - 1);
  // for(int i = 0; i < 30; i++) {
  //   for(int j = 0; j < 30; j++) {
  //     printf("%4d ", dp[i][j]);
  //   }
  //   cout << endl;
  // }
}