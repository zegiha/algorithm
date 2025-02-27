#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;
using pipii = pair <int, pii>;

int n, m, arr[103][103];
vector <pii> s;

const int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < n+2 && 0 <= c && c < m+2;
}
vector <vector <int>> get_dist(pii s) {
  vector <vector <int>> dist (n + 2, vector <int> (m + 2, -1));
  priority_queue <pipii, vector <pipii>, greater <pipii>> q;

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
        if(arr[nr][nc] == 2) nv++;
        if(dist[nr][nc] == -1 || nv < dist[nr][nc]) {
          q.push({nv, {nr, nc}});
          dist[nr][nc] = nv;
        }
      }
    }
  }

  // for(int i = 0; i < n + 2; i++) {
  //   for(int j = 0; j < m + 2; j++) {
  //     if(dist[i][j] == -1) cout << "X ";
  //     else cout << dist[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  return dist;
}

void solve() {
  s.clear();
  s.push_back({0, 0});

  cin >> n >> m;
  for(int i = 1; i < n+1; i++) {
    string str; cin >> str;
    for(int j = 1; j < m+1; j++) {
      if(str[j-1] == '*') arr[i][j] = -1;
      else if(str[j-1] == '.') arr[i][j] = 1;
      else if(str[j-1] == '#') arr[i][j] = 2;
      else if(str[j-1] == '$') {
        arr[i][j] = 1;
        s.push_back({i, j});
      }
    }
  }

  vector <vector <int>> sum_dist (n + 2, vector <int> (m + 2, 0));
  vector <vector <vector <int>>> dist_list;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++) {
    dist_list.push_back(get_dist(s[i]));
    for(int j = 0; j < dist_list[i].size(); j++) {
      for(int k = 0; k < dist_list[i][j].size(); k++) {
        sum_dist[j][k] += dist_list[i][j][k];
      }
    }
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}
