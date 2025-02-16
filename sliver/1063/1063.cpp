#include <iostream>
#include <string>

using namespace std;
using pii = pair <int, int>;

int arr[8][8];
pii k, s;

const string root_cmd[] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1}, dx[] = {1, -1, 0, 0, 1, -1, 1, -1};

int get_d(string cmd) {
  for(int i = 0; i < 8; i++) {
    if(cmd == root_cmd[i]) return i;
  }
}

bool is_area(int r, int c) {
  return 0 <= r && r < 8 && 0 <= c && c < 8;
}

string to_chess(pii coords) {
  string res = "";
  res += coords.second + 'A';
  res += coords.first + '1';
  return res;
}

int main() {
  for(int i = 0; i < 2; i++) {
    string t; cin >> t;
    pii res = {t[1] - '1', t[0] - 'A'};
    if(i == 0) k = res;
    else s = res;
  }

  int n, d;
  string cmd;

  cin >> n;
  while(n--) {
    // bool tsw = true;
    cin >> cmd;
    d = get_d(cmd);
    int nr = k.first + dy[d], nc = k.second + dx[d];
    if(is_area(nr, nc)) {
      pii new_coords = {nr, nc};
      if(s == new_coords) {
        nr = s.first + dy[d]; nc = s.second + dx[d];
        if(is_area(nr, nc)) {
          k = new_coords;
          s = {nr, nc};
          // tsw = false;
        }
      } else {
        k = {nr, nc};
          // tsw = false;
      }
    }

    // if(tsw) {
    //   cout << "stop\n";
    // } else {
    //   cout << "move\n";
    // }
  }

  cout << to_chess(k) << '\n' << to_chess(s);
}