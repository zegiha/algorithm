#include <iostream>

using namespace std;

int dp[101][101][81], n, m, ans, mult_n;
char arr[101][101];
string word;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool visit[101][101][81] = {0,};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int get_dp(int r, int c, int idx) {
  if(dp[r][c][idx] != -1) return dp[r][c][idx];
  if(idx >= word.size()) {
    dp[r][c][idx] = 1;
    return 1;
  }
  
  int new_dp = 0;
  for(int d = 0; d < 4; d++) {
    for(int mult = 1; mult <= mult_n; mult++) {
      int nr = r + dy[d] * mult, nc = c + dx[d] * mult;
      if(is_area(nr, nc) && word[idx] == arr[nr][nc]) {
        new_dp += get_dp(nr, nc, idx + 1);
      }
    }
  }
  
  dp[r][c][idx] = new_dp;
  return new_dp;
}

int main() {
  cin >> n >> m >> mult_n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  cin >> word;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k <= word.size(); k++) {
        dp[i][j][k] = -1;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(arr[i][j] == word[0]) {
        ans += get_dp(i, j, 1);
      }
    }
  }

  cout << ans;
}