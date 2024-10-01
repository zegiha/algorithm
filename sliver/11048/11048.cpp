#include <iostream>
#include <algorithm>

using namespace std;

int 
arr[1001][1001], dp[1001][1001],
n, m,
dy[] = {0, -1, -1}, dx[] ={-1, 0, -1};

bool isArea(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}
int getDp(int row, int col) {
  if(!isArea(row, col)) return 0;
  if(dp[row][col] != -1) return dp[row][col];

  for(int d = 0; d < 3; d++) {
    dp[row][col] = max(dp[row][col], getDp(row + dy[d], col + dx[d]) + arr[row][col]);
  }

  return dp[row][col];
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }

  cout << getDp(n - 1, m - 1);
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
}