#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coordinate {
  int row;
  int col;
};

int n, dy[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isArea(Coordinate m) {
  return m.row >= 0 && m.row < n && m.col >= 0 && m.col < n;
}
void solve() {
  Coordinate st, en;
  cin >> st.row >> st.col;
  cin >> en.row >> en.col;

  int ans = 0;
  vector<vector<bool>> visit(n, vector<bool>(n, false));
  queue <Coordinate> q;

  q.push(st);
  visit[st.row][st.col] = true;

  while(!q.empty()) {
    int size = q.size();
    while(size--) {
      Coordinate h = q.front();
      q.pop();

      if(h.row == en.row && h.col == en.col) {
        cout << ans << '\n';
        return;
      }

      for(int i = 0; i < 8; i++) {
        Coordinate m = {h.row + dy[i], h.col + dx[i]};
        if(isArea(m) && !visit[m.row][m.col]) {
          visit[m.row][m.col] = true;
          q.push(m);
        }
      }
    }
    ans++;
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n;
    solve();
  }
}