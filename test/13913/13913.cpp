#include <iostream>
#include <vector>

using namespace std;

int s, e;

const int dx[] = {1, -1};

vector <vector <int>> dp(100'001, vector <int> (1, -1));

bool is_area(int c) {
  return 0 <= c && c < 100'001;
}
vector <int> get_dp(int idx) {
  if(dp[idx][0] != -1) return dp[idx];

  vector <int> tmp, new_dp(1, -1);
  for(int d = 0; d < 2; d++) {
    if(!is_area(idx + dx[d])) continue;
    tmp = get_dp(idx + dx[d]);
    if(new_dp[0] == -1 || new_dp.size() > tmp.size())
      new_dp = tmp;
  }

  if(idx % 2 == 0) {
    tmp = get_dp(idx / 2);
    if(new_dp[0] == -1 || new_dp.size() > tmp.size())
      new_dp = tmp;
  }

  new_dp.push_back(idx);
  return new_dp;
}

int main() {
  cin >> s >> e;

  dp[s] = vector <int> (1, s);

  vector <int> ans = get_dp(e);

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}