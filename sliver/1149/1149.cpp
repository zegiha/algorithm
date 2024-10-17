#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001][3];

pair <int, int> getIdxs(int idx) {
  if(idx == 0) return {1, 2};
  else if(idx == 1) return {0, 2};
  else return {0, 1};
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> arr[i][j];

  int dp[] = {arr[0][0], arr[0][1], arr[0][2]}, newDp[3];
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      pair <int, int> idxs = getIdxs(j);
      newDp[j] = arr[i][j] + min(dp[idxs.first], dp[idxs.second]);
    }

    for(int t = 0; t < 3; t++) dp[t] = newDp[t];
  }

  cout << min({dp[0], dp[1], dp[2]});
}