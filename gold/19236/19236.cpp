#include <iostream>
#include <vector>

using namespace std;
using pii = pair <int, int>;
using piipi = pair <pii, int>;

int n = 4, ans = 0;
vector <pii> fish_cdn(16);
vector <vector <pii>> arr(4, vector <pii> (4));
vector <vector <bool>> visit(4, vector <bool> (4, false));

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < n;
}

bool is_shark(pii shark, int r, int c) {
  return r == shark.first && c == shark.second;
}
void fish_move(pii shark) {
  for(pii& f : fish_cdn) {
    if(!visit[f.first][f.second]) {
      int d = arr[f.first][f.second].second;
      int
        nr = f.first + dy[d],
        nc = f.second + dx[d];
      while(!(is_area(nr, nc) && !is_shark(shark, nr, nc))) {
        d = (d + 1) % 8;
        nr = f.first + dy[d];
        nc = f.second + dx[d];
      }
      arr[f.first][f.second].second = d;

      pii t = arr[nr][nc];
      arr[nr][nc] = arr[f.first][f.second];
      arr[f.first][f.second] = t;

      if(visit[nr][nc]) {
        visit[nr][nc] = false;
        visit[f.first][f.second] = true;
      }
    }
  }
}

void solve(int r, int c, int d, int cnt) {
  vector <pii> can_move;
  int nr = r + dy[d], nc = c + dx[d];
  while(is_area(nr, nc)) {
    if(!visit[nr][nc]) can_move.push_back({nr, nc});

    nr += dy[d];
    nc += dx[d];
  }

  if(can_move.empty()) {
    ans = max(ans, cnt);
    return;
  } else {
    for(pii m : can_move) {
      vector <vector <pii>> prev_arr = arr;
      vector <pii> prev_fish_cdn = fish_cdn;
      vector <vector <bool>> prev_visit = visit;
      visit[m.first][m.second] = true;
      fish_move({r, c});
      solve(m.first, m.second, arr[m.first][m.second].second, cnt + arr[m.first][m.second].second);
      arr = prev_arr;
      fish_cdn = prev_fish_cdn;
      visit = prev_visit;
    }
  }
}

int main() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j].first >> arr[i][j].second;
      arr[i][j].first--; arr[i][j].second--;
      fish_cdn[arr[i][j].first] = {i, j};
    }
  }

  visit[0][0] = true;
  solve(0, 0, arr[0][0].second, arr[0][0].first);
  visit[0][0] = false;

  cout << ans;
}