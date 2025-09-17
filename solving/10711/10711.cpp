#include <iostream>
#include <queue>

using namespace std;
using pii = pair <int, int>;

const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1}, dx[] = {1, -1, 0, 0, -1, 1, 1, -1};

int n, m, arr[1001][1001], newArr[1001][1001];

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

bool isBreak(int r, int c) {
  int cnt = 0;
  for(int d = 0; d < 8; d++) {
    if(arr[r + dy[d]][c + dx[d]] <= 0) {
      cnt++;
    }
  }

  return arr[r][c] <= cnt;
}

bool isBreakNext(int r, int c) {
  int cnt = 0;
  for(int d = 0; d < 8; d++) {
    if(newArr[r + dy[d]][c + dx[d]] <= 0) {
      cnt++;
    }
  }

  return newArr[r][c] <= cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  queue <pii> q;

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    for(int j = 0; j < m; j++) {
      if(t[j] == '.') {
        arr[i][j] = newArr[i][j] = 0;
      }
      else arr[i][j] = newArr[i][j] = t[j] - '0';
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(isBreak(i, j)) {
        q.push({i, j});
        newArr[i][j] = 0;
      }
    }
  }

  int ans = 0;
  bool visited[1001][1001];
  while(!q.empty()) {
    int size = q.size();
    ans++;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
      visited[i][j] = false;
      arr[i][j] = newArr[i][j];
    }
    // cout << "========================\n";

    while(size--) {
      auto [r, c] = q.front();
      // cout << r << ' ' << c << '\n';
      q.pop();

      for(int d = 0; d < 8; d++) {
        int nr = r + dy[d], nc = c + dx[d];

        if(isArea(nr, nc) && !visited[nr][nc] && arr[nr][nc] > 0) {
          visited[nr][nc] = true;
          if(isBreak(nr, nc)) {
            q.push({nr, nc});
            newArr[nr][nc] = 0;
          }
        }
      }
    }
    // cout << "========================\n";

    // cout << "========================\n";
    // for(int i = 0; i < n; i++) {
    //   for(int j = 0; j < m; j++) {
    //     cout << arr[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << "========================\n";
  }

  cout << ans;
}