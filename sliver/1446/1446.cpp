#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ppiii = pair <pair <int, int>, int>;

int n, dp[10'002];
vector <ppiii> arr;

int get_dp(int idx) {
  if(dp[idx] != -1) return dp[idx];

  int new_dp = get_dp(idx - 1) + 1;
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i].first.second == idx) {
      new_dp = min(new_dp, get_dp(arr[i].first.first) + arr[i].second);
    }
  }

  return dp[idx] = new_dp;
}

int main() {
  int t;
  cin >> t >> n;
  for(int i = 0; i <= n; i++) dp[i] = -1;
  dp[0] = 0;

  while(t--) {
    int f, t, v; cin >> f >> t >> v;
    arr.push_back({{f, t}, v});
  }

  cout << get_dp(n);
}