#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;
using pipii = pair <int, pii>;

int h, w;
vector <vector <int>> arr;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < h + 2 && 0 <= c && c < w + 2;
}
vector <vector <int>> get_dist(pii s) {
  priority_queue <pipii, vector <pipii>, greater<pipii>> q;
  vector <vector <int>> dist(h + 2, vector <int> (w + 2, -1));

  q.push({0, s});
  dist[s.first][s.second] = 0;

  while(!q.empty()) {
    int v = q.top().first, r = q.top().second.first, c = q.top().second.second;

    q.pop();
    if(dist[r][c] != -1 && dist[r][c] < v) continue;

    for(int d = 0; d < 4; d++) {
      int nr = r + dy[d], nc = c + dx[d];
      if(is_area(nr, nc) && arr[nr][nc] != -1) {
        int nv = v;
        if(arr[nr][nc] == 1) nv++;
        if(dist[nr][nc] > nv || dist[nr][nc] == -1) {
          q.push({nv, {nr, nc}});
          dist[nr][nc] = nv;
        }
      }
    }
  }

  // for(int i = 0; i < dist.size(); i++) {
  //   for(int j = 0; j < dist[i].size(); j++) {
  //     if(dist[i][j] == -1) cout << "X ";
  //     else cout << dist[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << "=====================\n\n";

  return dist;
}

void solve() {
  cin >> h >> w;

  arr.clear();
  arr.resize(h + 2, vector <int> (w + 2, 0));

  vector <pii> s, doors;

  for(int i = 1; i < h+1; i++) {
    string str; cin >> str;
    for(int j = 0; j < w+1; j++) {
      if(str[j-1] == '*') arr[i][j] = -1;
      if(str[j-1] == '.') arr[i][j] = 0;
      if(str[j-1] == '#') {
        arr[i][j] = 1;
        doors.push_back({i, j});
      }
      if(str[j-1] == '$') {
        s.push_back({i, j});
        arr[i][j] = 2;
      }
    }
  }
  s.push_back({0, 0});

  int ans = 0;
  vector <vector <vector <int>>> dist_list;
  for(int i = 0; i < 3; i++) {
    dist_list.push_back(get_dist(s[i]));
    ans += dist_list[i][0][0];
  }

  // cout << "=====================" << ans << '\n';

  for(pii c : doors) {
    int sum = -2;
    for(int i = 0; i < dist_list.size(); i++) sum += dist_list[i][c.first][c.second];
    ans = min(ans, sum);
  }

  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}