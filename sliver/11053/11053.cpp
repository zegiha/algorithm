#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001], dp[1001], ans;

int getDp(int idx) {
if(dp[idx] != -1) return dp[idx];

  int biggest = 0;
  for(int i = idx + 1; i < n; i++) {
    if(arr[idx] < arr[i]) biggest = max(biggest, getDp(i));
  }
  dp[idx] = biggest + 1;

  return dp[idx];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    dp[i] = -1;
  }

  for(int i = 0; i < n; i++) {
    ans = max(ans, getDp(i));
  }

  cout << ans;
}