#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int n, m, arr[1001][1001];
vector <pii> fire;

const int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

bool is_end(int r, int c) {
  if(r == 0 || r == n-1) return true;
  if(c == 0 || c == m-1) return true;
  return false;
}

void solve() {
  fire.clear();
  pii start_cdn;
  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    for(int j = 0; j < m; j++) {
      if(s[j] == '#') arr[i][j] = -1;
      else if(s[j] == '.') arr[i][j] = 0;
      else if(s[j] == '@') {
        arr[i][j] = 0;
        start_cdn = {i, j};
      } else {
        arr[i][j] = 1;
        fire.push_back({i, j});
      }
    }
  }


  queue <pii> hq;
  vector <vector <bool>> h_visit(n+1, vector <bool> (m+1, false));

  queue <pii> fq;
  vector <vector <bool>> f_visit(n+1, vector <bool> (m+1, false));

  hq.push(start_cdn);
  h_visit[start_cdn.first][start_cdn.second] = true;

  for(pii p : fire) {
    fq.push(p);
    f_visit[p.first][p.second] = true;
  }

  int r, c, nr, nc, ans = 0;
  bool sw = false;

  while((!hq.empty() || !fq.empty()) && !sw) {
    ans++;
    int size = fq.size();
    while(size--) {
      r = fq.front().first; c = fq.front().second;
      fq.pop();
      for(int d = 0; d < 4; d++) {
        nr = r + dy[d]; nc = c + dx[d];
        if(is_area(nr, nc) && !f_visit[nr][nc] && arr[nr][nc] == 0) {
          fq.push({nr, nc});
          f_visit[nr][nc] = true;
          arr[nr][nc] = 1;
        }
      }
    }
    
    size = hq.size();
    while(size--) {
       r = hq.front().first; c = hq.front().second;
       hq.pop();
      for(int d = 0; d < 4; d++) {
        nr = r + dy[d]; nc = c + dx[d];
        if(is_area(nr, nc)) {
          if(!h_visit[nr][nc] && arr[nr][nc] == 0) {
            hq.push({nr, nc});
            h_visit[nr][nc] = true;
          }
        } else {
          sw = true;
        }
      }
    }
  }

  if(sw) cout << ans << '\n';
  else cout << "IMPOSSIBLE\n";
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}