#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m, k, ans, dp[501][501];
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
char arr[501][501];
string goal;
bool visit[501][501] = {0,};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int get_dp(int r, int c, string str) {
  if(dp[r][c] != -1) return dp[r][c];
  if(str == goal) return 1;

  int new_dp = 0;
  for(int d = 0; d < 4; d++) {
    for(int mult = 1; mult <= k; mult++) {
      int nr = r + dy[d] * mult, nc = c + dx[d] * mult;
      // if(!(goal[str.size()] == arr[nr][nc])) {
      //   cout << str.size() << ' '<< nr << ' ' << nc << endl;
      //   cout << "============================\n";
      // }
      if(is_area(nr, nc) && !visit[nr][nc] && goal[str.size()] == arr[nr][nc]) {
        // cout << "dldld?\n";
        str.push_back(arr[nr][nc]);
        visit[nr][nc] = true;
        new_dp += get_dp(nr, nc, str);
        str.pop_back();
        visit[nr][nc] = false;
      }
    }
  }

  dp[r][c] = new_dp;
  return dp[r][c];
}

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      dp[i][j] = -1;
    }
  }
  cin >> goal;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(arr[i][j] == goal[0]) {
        ans += get_dp(i, j, string(1, arr[i][j]));
      }
    }
  }

  cout << ans;
}