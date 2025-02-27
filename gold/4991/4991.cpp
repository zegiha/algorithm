#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int n, m, arr[21][21], ans = 2'100'000'000;
vector <pii> trash_and_start;
pii robot_start;
vector <vector <int>> min_dist;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}
void set_min_dist(int idx) {
  int cnt = 1;
  queue <pii> q;
  vector <vector <bool>> visit(n, vector <bool> (m, false));
  
  q.push({trash_and_start[idx]});
  visit[trash_and_start[idx].first][trash_and_start[idx].second] = true;
  min_dist[idx][idx] = 0;

  while(!q.empty()) {
    int size = q.size();
    while(size--) {
      int r = q.front().first, c = q.front().second;
      q.pop();
      for(int d = 0; d < 4; d++) {
        int nr = r + dy[d], nc = c + dx[d];
        if(is_area(nr, nc) && !visit[nr][nc] && arr[nr][nc] == 1) {
          q.push({nr, nc});
          visit[nr][nc] = true;
          for(int i = 0; i < trash_and_start.size(); i++) {
            if(trash_and_start[i].first == nr && trash_and_start[i].second == nc) {
              min_dist[idx][i] = cnt;
            }
          }
        }
      }
    }
    cnt++;
  }
}

vector <bool> check;
void set_ans(int d, int prev, int cnt) {
  if(d == min_dist.size()) {
    // cout << cnt << ' ';
    if(cnt < ans) ans = cnt;
    return;
  }

  for(int i = 0; i < min_dist.size(); i++) {
    if(!check[i]) {
      check[i] = true;
      set_ans(d + 1, i, cnt + min_dist[prev][i]);
      check[i] = false;
    }
  }
}

void solve() {
  check.clear();
  min_dist.clear();
  trash_and_start.clear();
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    for(int j = 0; j < m; j++) {
      if(str[j] =='x') arr[i][j] = -1;
      else {
        arr[i][j] = 1;
        if(str[j] == '*') trash_and_start.push_back({i, j});
        else if(str[j] == 'o') robot_start = {i, j};
      }
    }
  }

  trash_and_start.insert(trash_and_start.begin(), robot_start);

  min_dist.resize(trash_and_start.size(), vector <int> (trash_and_start.size(), -1));
  for(int i = 0; i < trash_and_start.size(); i++) {
    set_min_dist(i);
    for(int j = 0; j < min_dist[i].size(); j++) {
      if(min_dist[i][j] == -1) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  check.resize(min_dist.size(), false);
  check[0] = true;
  ans = 2'100'000'000;
  set_ans(1, 0, 0);

  // cout << "====================";
  cout << ans << '\n';
}

int main() {
  while(true) {
    cin >> m >> n;
    if(n == 0 && m == 0) break;
    solve();
  }
}