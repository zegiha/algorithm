#include <iostream>

using namespace std;

long long dp[101];

long long getDp(int n) {
  if(dp[n] != -1) return dp[n];
  dp[n] = getDp(n - 1) + getDp(n - 5);

  return dp[n];
}

int main() {
  //init
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tmp[] = {-1, 1, 1, 1, 2, 2};
  for(int i = 1; i <= 5; i++) dp[i] = tmp[i];
  for(int i = 6; i < 101; i++) dp[i] = -1;
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    cout << getDp(n) << '\n';
  }
  return 0;
}