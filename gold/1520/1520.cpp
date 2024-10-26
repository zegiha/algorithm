#include <iostream>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
int n, m, arr[501][501], dp[501][501];

bool isArea(int row, int col) {
  return  0 <= row && row < n && 0 <= col && col < m;
}

bool visit[501][501] = {0, };
int getDp(int row, int col) {
  if(dp[row][col] != -1) return dp[row][col];

  int r, c, cnt = 0;
  for(int d = 0; d < 4; d++) {
    r = row + dy[d]; c = col + dx[d];
    
    if(isArea(r, c) && arr[row][col] > arr[r][c] && !visit[r][c]) {
      if(r == n - 1 && c == m - 1) {
        cnt++;
      } else {
        visit[r][c] = true;
        cnt += getDp(r, c);
        visit[r][c] = false;
      }
    }
  }

  return dp[row][col] = cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  dp[n - 1][m - 1] = 1;
  cout << getDp(0, 0);
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }
}