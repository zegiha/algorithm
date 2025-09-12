#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using tiiiii = tuple <int, int, int, int, int>;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int n, m, k, arr[1001][1001];
bool visited[1001][1001][11];

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    for(int j = 0; j < m; j++) {
      arr[i][j] = t[j] - '0';
    }
  }

  queue <tiiiii> q;

  q.push({1, 0, 0, 0, 0});
  visited[0][0][0] = true;

  while(!q.empty()) {
    auto [moveCnt, isNight, breakCnt, r, c] = q.front();
    q.pop();

    if(r == n-1 && c == m-1) {
      cout << moveCnt;
      return 0;
    }

    for(int d = 0; d < 4; d++) {
      int nr = r + dy[d], nc = c + dx[d];

      if(isArea(nr, nc)) {
        if(arr[nr][nc] == 1) {
          if(breakCnt < k) {
            if(!visited[nr][nc][breakCnt + 1]) {
              if(!isNight) {
                q.push({moveCnt + 1, !isNight, breakCnt + 1, nr, nc});
                visited[nr][nc][breakCnt + 1] = true;
              } else {
                q.push({moveCnt + 1, !isNight, breakCnt, r, c});
              }
            }
          }
        } else if(arr[nr][nc] == 0) {
          if(!visited[nr][nc][breakCnt]) {
            q.push({moveCnt +1, !isNight, breakCnt, nr, nc});
            visited[nr][nc][breakCnt] = true;
          }
        }
      }
    }
  }

  cout << -1;
}