#include <iostream>
#include <queue>

using namespace std;

int arr[51][51], n, m;
bool visit[51][51];
queue <pair <int, int>> q;

const int dy[] = {1, 1, 1, 0, -1, -1, -1, 0}, dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
  int cnt = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if(arr[i][j] == 1) {
        visit[i][j] = true;
        q.push({i, j});
      } else {
        cnt++;
      }
      arr[i][j]--;
    }
  }

  int ans = 0;
  while(!q.empty()) {
    int size = q.size();
    if(cnt <= 0) {
      cout << ans;
      return 0;
    }
    while(size--) {
      int r = q.front().first, c = q.front().second;
      q.pop();
      for(int d = 0; d < 8; d++) {
        int nr = r + dy[d], nc = c + dx[d];
        if(is_area(nr, nc) && !visit[nr][nc]) {
          visit[nr][nc] = true;
          q.push({nr, nc});
          arr[nr][nc] = ans + 1;
          cnt--;
        }
      }
    }
    ans++;
  }
}