#include <iostream>

using namespace std;

const int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};

int renew_abs(int a) {
  if(a < 0) return a * -1;
  return a;
}

void solve() {
  string cmd; cin >> cmd;
  int row = 0, col = 0, d = 0;;
  pair <int, int> minc = {0, 0}, maxc = {0, 0};

  for(int i = 0; i < cmd.size(); i++) {
    char c = cmd[i];
    if(c == 'F') {
      row += dy[d]; col += dx[d];
    } else if(c == 'B') {
      row -= dy[d]; col -= dx[d];
    } else if(c == 'L') {
      d = (d + 1) % 4;
    } else {
      d -= 1;
      if(d == -1) d = 3;
    }
    
    if(minc.first > row) minc.first = row;
    if(minc.second > col) minc.second = col;
    if(maxc.first < row) maxc.first = row;
    if(maxc.second < col) maxc.second = col;

    // cout << row << ' ' << col << ' ' << d << '\n';
  }

  cout << (abs(minc.first) + maxc.first) * (abs(minc.second) + maxc.second) << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}