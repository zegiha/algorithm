#include <iostream>
#include <vector>

using namespace std;

int n, arr[1001];
vector <vector <int>> dp;

vector <int> get_dp(int idx) {
  if(!dp[idx].empty()) return dp[idx];

  vector <int> new_dp(1, arr[idx]), tmp;
  for(int i = idx + 1; i < n; i++) {
    tmp = get_dp(i);
    if(arr[idx] < tmp[0]) {
      tmp.insert(tmp.begin(), arr[idx]);
      if(new_dp.size() < tmp.size()) new_dp = tmp;
    }
  }

  return dp[idx] = new_dp;
}

int main() {
  cin >> n;
  dp.resize(n, vector <int> (0));
  for(int i = 0; i < n; i++) cin >> arr[i];

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(get_dp(i).size() > get_dp(ans).size()) ans = i;
  }

  // for(int i = 0; i < dp.size(); i++) {
  //   cout << i << " : ";
  //   for(int j = 0; j < dp[i].size(); j++) cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }

  cout << dp[ans].size() << '\n';
  for(int i = 0; i < dp[ans].size(); i++) cout << dp[ans][i] << ' ';
}