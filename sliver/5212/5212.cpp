#include <iostream>
#include <vector>

using namespace std;

int arr[11][11], n, m, ans, new_arr[11][11];
vector <pair <int, int>> land, new_land;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      if(c == '.') {
        arr[i][j] = new_arr[i][j] = 0;
      }
      else {
        arr[i][j] = new_arr[i][j] = 1;
        land.push_back({i, j});
      }
    }
  }

  for(int i = 0; i < land.size(); i++) {
    int cnt = 0, nr, nc;
    for(int d = 0; d < 4; d++) {
      nr = land[i].first + dy[d]; nc = land[i].second + dx[d];
      if((!is_area(nr, nc)) || (is_area(nr, nc) && arr[nr][nc] == 0)) cnt++;
    }
    if(cnt >= 3) {
      new_arr[land[i].first][land[i].second] = 0;
    } else {
      new_land.push_back(land[i]);
    }
  }

  pair <int, int> row = {2'100'000'000, -1}, col = {2'100'000'000, -1};
  for(int i = 0; i < new_land.size(); i++) {
    int r = new_land[i].first, c = new_land[i].second;
    if(row.first > r) {
      row.first = r;
    }
    if(row.second < r) {
      row.second = r;
    }
    if(col.first > c) {
      col.first = c;
    }
    if(col.second < c) {
      col.second = c;
    }
  }

  for(int i = row.first; i <= row.second; i++) {
    for(int j = col.first; j <= col.second; j++) {
      if(new_arr[i][j]) cout << 'X';
      else cout << '.';
    }
    cout << '\n';
  }
}