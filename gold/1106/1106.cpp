#include <iostream>

using namespace std;
using pii = pair <int, int>;

int c, n, dp[100'001];
pii arr[20];

int main() {
  cin >> c >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  int ans = 100'002;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= min(100'000, ans); j++) {
      if(j - arr[i].first < 0) continue;
      dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
      if(dp[j] >= c) {
        ans = j;
        break;
      }
    }
  }

  cout << ans;
}