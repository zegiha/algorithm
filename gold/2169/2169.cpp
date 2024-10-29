#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[1001][1001], dp[1001][1001][3];
const int dy[] = {0, 0, 1}, dx[] = {1, -1, 0};

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

bool visit[1001][1001] = {0, };
int getDp(int r, int c, int dir) {
  if(r == n - 1 && c == m - 1) return arr[r][c];
  if(dp[r][c][dir] != -2100000000) return dp[r][c][dir];

  visit[r][c] = true;

  int nr, nc, biggest = -2100000000;
  for(int d = 0; d < 3; d++) {
    nr = r + dy[d]; nc = c + dx[d];
    if(isArea(nr, nc) && !visit[nr][nc]) {
      biggest = max(biggest, getDp(nr, nc, d));
    }
  }

  visit[r][c] = false;
  dp[r][c][dir] = biggest + arr[r][c];

  return dp[r][c][dir];
}
int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      dp[i][j][0] = -2100000000;
      dp[i][j][1] = -2100000000;
      dp[i][j][2] = -2100000000;
    }
  }

  cout << getDp(0, 0, 0);
}