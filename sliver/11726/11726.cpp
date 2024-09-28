#include <iostream>
#include <cstring>

using namespace std;

int dp[1001];

int getDp(int n) {
  if(n == 2) return 2;
  else if(n == 1) return 1;

  if(dp[n] != -1) return dp[n];

  dp[n] = getDp(n - 1) + getDp(n - 2);

  return dp[n] % 10'007;
}

int main() {
  int n; cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << getDp(n);
}