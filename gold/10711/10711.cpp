#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using pii = pair <int, int>;

const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx[] = {1, -1, 0, 0, -1, 1, 1, -1};

int n, m, arr[1001][1001], ans;

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

bool isBreakNext(int r, int c, int (&arr)[1001][1001]) {
  int cnt = 0, nr, nc;
  for(int d = 0; d < 8; d++) {
    nr = r + dy[d], nc = c + dx[d];
     if(isArea(nr, nc) && arr[nr][nc] == 0) cnt++;
  }

  return arr[r][c] <= cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    for(int j = 0; j < m; j++) {
      if(t[j] == '.') arr[i][j] = 0;
      else arr[i][j] = t[j] - '0';
    }
  }

  queue <pii> q;
  vector <tuple<int, int, int>> changed;
  bool visited[1001][1001] = {0, };

  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
    if(isBreakNext(i, j, arr)) {
      q.push({i, j});
      changed.push_back({i, j, 0});
      visited[i][j] = true;
    }
  }

  while(!q.empty()) {

    int size = q.size(), nr, nc;
    ans++;

    for(tuple <int, int, int> v : changed) {
      auto [i, j, newV] = v;
      arr[i][j] = newV;
    }
    changed.clear();

    while(size--) {
      auto [r, c] = q.front();
      q.pop();

      for(int d = 0; d < 8; d++) {
        nr = r + dy[d], nc = c + dx[d];
        if(
          isArea(nr, nc) &&
          arr[nr][nc] != 0 &&
          isBreakNext(nr, nc, arr) &&
          !visited[nr][nc]
        ) {
          visited[nr][nc] = true;
          q.push({nr, nc});
          changed.push_back({nr, nc, 0});
        }
      }
    }
  }

  cout << ans;
}
