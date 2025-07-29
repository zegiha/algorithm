#include <iostream>

using namespace std;
using ll = long long;

ll k, n, dp[74][138];

ll getDp(ll second, ll height) {
  if(dp[second][height] != -1) return dp[second][height];
  if(height <= 0) return dp[second][height] = 0;
  if(second <= 0) return dp[second][height] = 1;

  return dp[second][height] = getDp(second - 1, height - 1) + getDp(second - 1, height + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k >> n;
  for(int i = 0; i < 64 + 10; i++) for(int j = 0; j < 128 + 10; j++) dp[i][j] = -1;

  cout << getDp(n, k);
}