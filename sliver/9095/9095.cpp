#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[101];
int getDp(int n) {
  // base cases
  if(n == 1) return 1;
  else if(n == 2) return 2;
  else if(n == 3) return 4;

  if(dp[n] != -1) return dp[n];
  dp[n] = getDp(n - 1) + getDp(n - 2) + getDp(n - 3);

  return dp[n];   
}

void solve() {
  int n; cin >> n;
  cout << getDp(n) << '\n';
}

int main() {
  int t; cin >> t;
  memset(dp, -1, sizeof(dp));
  while(t--) {
    solve();
  }
}