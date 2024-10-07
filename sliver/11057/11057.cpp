#include <iostream>

using namespace std;

int n, dp[10], prevDp[10];

void prevDpToDp() {
  for(int i = 0; i < 10; i++) {
    prevDp[i] = dp[i];
  }
}

int getPrevDpSumInRange(int i) {
  int sum = 0;
  for(; i < 10; i++) {
    sum = (sum + prevDp[i]) % 10007;
  }
  return sum;
}

int main() {
  cin >> n; n--;
  for(int i = 0; i < 10; i++) dp[i] = 1;
  while(n--) {
    prevDpToDp();
    for(int i = 0; i < 10; i++) {
      dp[i] = getPrevDpSumInRange(i);
    }
  }

  int ans = 0;
  for(int i = 0; i < 10; i++) {
    ans = (ans + dp[i]) % 10007;
  }

  cout << ans;
}