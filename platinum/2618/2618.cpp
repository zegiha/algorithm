#include <iostream>

using namespace std;
using pii = pair <int, int>;

int n, w, dp[1001][1001];
pii arr[1001];

int getLength(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int getMinDist(int p1, int p2)  {
  if(dp[p1][p2] != -1) return dp[p1][p2];

  int next = max(p1, p2) + 1;
  if(next == w + 1) return 0;

  pii p1Cdn, p2Cdn;
  if(p1 == 0) p1Cdn = {1, 1};
  else p1Cdn = arr[p1];
  if(p2 == 0) p2Cdn = {n, n};
  else p2Cdn = arr[p2];

  dp[p1][p2] = min(
    getLength(p1Cdn, arr[next]) + getMinDist(next, p2),
    getLength(p2Cdn, arr[next]) + getMinDist(p1, next)
  );

  return dp[p1][p2];
}

void printTrace(int p1, int p2) {
  int next = max(p1, p2) + 1;
  if(next  == w + 1) return;

  pii p1Cdn, p2Cdn;
  if(p1 == 0) p1Cdn = {1, 1};
  else p1Cdn = arr[p1];
  if(p2 == 0) p2Cdn = {n, n};
  else p2Cdn = arr[p2];

  if(dp[next][p2] + getLength(p1Cdn, arr[next]) < dp[p1][next] + getLength(p2Cdn, arr[next])) {
    cout << 1 << '\n';
    printTrace(next, p2);
  } else {
    cout << 2 << '\n';
    printTrace(p1, next);
  }
}

int main() {
  cin >> n >> w;
  for(int i = 1; i <= w; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  for(int i = 0; i <= w; i++) for(int j = 0; j <= w; j++) dp[i][j] = -1;

  cout << getMinDist(0, 0) << '\n';
  printTrace(0, 0);
}