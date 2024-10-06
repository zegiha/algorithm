#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001], dp[1001];

int main() {
  cin >> n; for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = n; i >= 0; i--) {
    for(int j = 0; j < i; j++) {
      dp[i - (j + 1)] = max(dp[i - (j + 1)], dp[i] + arr[j]);
    }
  }

  cout << dp[0];
}