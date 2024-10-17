#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100'002], dp[100'002];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  int ans = dp[0] = arr[0];
  for(int i = 1; i < n; i++) {
    dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    if(ans < dp[i]) ans = dp[i];
  }

  cout << ans;
}