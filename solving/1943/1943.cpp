#include <iostream>
#include <vector>

#define TOTAL_MAX 100000

using namespace std;

int getComp(int total, int v) {
  return abs(total/2 - v);
}

void solve(int tmp) {
  int n = tmp, total = 0, dp[100'001] = {0,};
  vector<int> arr;

  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    while(b--) {
      arr.push_back(a);
      total += a;
    }
  }

  if(total % 2 != 0) {
    cout << 0 << '\n';
    return;
  }

  n = arr.size();
  dp[0] = 1;

  for(int idx = 0; idx < n; idx++) {
    for(int i = TOTAL_MAX; i >= 0; i--) {
      if(dp[i]) dp[i + arr[idx]] = 1;
    }
  }

  cout << dp[total / 2] << '\n';
}

int main() {
  int n;
  while(cin >> n) {
    solve(n);
  }
}