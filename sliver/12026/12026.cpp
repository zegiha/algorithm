#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1001];
string arr;

char get_target(char c) {
  if(c == 'B') return 'J';
  if(c == 'O') return 'B';
  return 'O';
}
int get_dp(int idx) {
  if(dp[idx] != -1) return dp[idx];
  if(idx == 0) return dp[idx] = 0;

  int new_dp = 2'100'000'000;
  char target = get_target(arr[idx]);
  for(int i = 0; i < idx; i++) {
    if(arr[i] == target) {
      int length = idx - i;
      new_dp = min(new_dp, get_dp(i) + (length * length));
    }
  }

  return dp[idx] = new_dp;
}

int main() {
  cin >> n >> arr;
  for(int i = 0; i < n; i++) dp[i] = -1;

  int ans = get_dp(n - 1);
  if(dp[0] != -1 && ans != 2'100'000'000) {
    cout << get_dp(n - 1);
  } else {
    cout << -1;
  }
}