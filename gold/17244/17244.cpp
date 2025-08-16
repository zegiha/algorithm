#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using pii = pair<int, int>;
using tiii = tuple <int, int, int>;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int maxCol, maxRow, arr[50][50], ans;
pii s;
vector <pii> itemLocation;

void input() {
  cin >> maxCol >> maxRow;
  for(int i = 0; i < maxRow; i++) {
    string t; cin >> t;
    for(int j = 0; j < maxCol; j++) {
      switch(t[j]) {
        case '.': {
          arr[i][j] = 0;
          break;
        }
        case '#': {
          arr[i][j] = -1;
          break;
        }
        case 'S': {
          s = {i, j};
          arr[i][j] = 0;
          break;
        }
        case 'X': {
          itemLocation.push_back({i, j});
          arr[i][j] = 1;
          break;
        }
        case 'E': {
          arr[i][j] = 2;
          break;
        }
      }
    }
  }
}

bool isArea(int r, int c) {
  return 0 <= r && r < maxRow && 0 <= c && c < maxCol;
}

bool isGetAllItem(int m) {
  return (1 << itemLocation.size()) - 1 == m;
}

int getTargetItemIdx(int r, int c) {
  for(int i = 0; i < itemLocation.size(); i++) {
    if(itemLocation[i].first == r && itemLocation[i].second == c) {
      return i;
    }
  }

  return -1;
}

bool isVisitItem(int targetItemIdx, int m) {
  return m & (1 << targetItemIdx);
}

int main() {
  input();

  queue <tiii> q;
  bool visit[50][50][1 << 6] = {0, };

  q.push({s.first, s.second, 0});
  visit[s.first][s.second][0] = true;

  while(!q.empty()) {
    int size = q.size();
    ans++;
    while(size--) {
      auto [r, c, m] = q.front();
      q.pop();

      for(int d = 0; d < 4; d++) {
        int nr = r + dy[d], nc = c + dx[d];

        if(isArea(nr, nc) && arr[nr][nc] != -1 && !visit[nr][nc][m]) {
          if(isGetAllItem(m) && arr[nr][nc] == 2) {
            cout << ans;
            return 0;
          } else {
            if(arr[nr][nc] == 1) {
              int itemIdx = getTargetItemIdx(nr, nc);
              if(!isVisitItem(itemIdx, m)) {
                int nm = m | (1 << itemIdx);
                visit[nr][nc][nm] = true;
                q.push({nr, nc, nm});
              } else {
                visit[nr][nc][m] = true;
                q.push({nr, nc, m});
              }
            } else {
              visit[nr][nc][m] = true;
              q.push({nr, nc, m});
            }
          }
        }
      }
    }
  }
}