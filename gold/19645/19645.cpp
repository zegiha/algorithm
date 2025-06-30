#include <iostream>

#define NMAX 50
#define VMAX 2501

using namespace std;

int n, inp[NMAX], dp[VMAX][VMAX];

int main() {
  int sum = 0, tot = 0, ans = 0, tmp;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> inp[i];
    sum += inp[i];
  }

  dp[0][0] = 1;
  for(int idx = 0; idx < n; idx++) {
    tot += inp[idx];

    for(int i = tot; i >= 0; i--) {
      for(int j = tot; j >= 0; j--) {
        if(dp[i][j]) {
          dp[i + inp[idx]][j] = 1;
          dp[i][j + inp[idx]] = 1;
        }
      }
    }
  }

  for(int i = 0; i <= sum; i++) {
    for(int j = 0; j <= sum; j++) {
      if(!dp[i][j]) continue;
      tmp = min(sum - (i + j), min(i, j));
      ans = max(ans, tmp);
    }
  }

  cout << ans;
}