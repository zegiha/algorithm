#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct CDN {
int row;
int col;
};

int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int n, m, k, arr[100][100] = {0, };
bool visit[100][100] = {0, };
vector <int> ans;

bool isArea(int row, int col) {
  return row >= 0 && row < n && col >= 0 && col < m;
}
void checkNewAns(int row, int col) {
  int cnt = 1;
  queue <CDN> q;
  q.push({row, col});
  visit[row][col] = true;
  while(!q.empty()) {
    CDN f = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      int nr = f.row + dy[d], nc = f.col + dx[d];
      if(isArea(nr, nc) && !visit[nr][nc]) {
        cnt++;
        visit[nr][nc] = true;
        q.push({nr, nc});
      }
    }
  }
  ans.push_back(cnt);
}

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) arr[i][j] = 1;
  for(int t = 0; t < k; t++) {
    CDN s, e;
    cin >> s.col >> s.row >> e.col >> e.row;
    for(int i = s.row; i < e.row; i++) {
      for(int j = s.col; j < e.col; j++) {
        arr[i][j] = 0;
        visit[i][j] = true;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!visit[i][j]) {
        checkNewAns(i, j);
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}