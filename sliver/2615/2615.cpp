#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int arr[19][19], n = 19;
vector <pii> b, w;

const int dy[2][4] = {
  {-1, -1, 0, 1},
  {1, 1, 0, -1},
};
const int dx[2][4] = {
  {0, 1, 1, 1},
  {0, -1, -1, -1}
  };

bool cmp(pii a, pii b) {
  if(a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < n;
}

bool is_win(pii s) {
  for(int d = 0; d < 4; d++) {
    int r = s.first, c = s.second, cnt = 0;

    while(is_area(r, c) && arr[r][c] == arr[s.first][s.second]) {
      r += dy[0][d];
      c += dx[0][d];
      cnt++;
    }
    r = s.first; c = s.second; cnt--;
    while(is_area(r, c) && arr[r][c] == arr[s.first][s.second]) {
      r += dy[1][d];
      c += dx[1][d];
      cnt++;
    }

    if(cnt == 5) {
      return true;
    }
  }
  return false;
}

int main() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if(arr[i][j] == 1) {
        b.push_back({i, j});
      } else if(arr[i][j] == 2) {
        w.push_back({i, j});
      }
    }
  }

  sort(b.begin(), b.end(), cmp);
  sort(w.begin(), w.end(), cmp);

  for(int i = 0; i < b.size(); i++) {
    pii c = b[i];
    if(is_win(c)) {
      cout << 1 << '\n';
      cout << c.first + 1 << ' ' << c.second + 1;
      return 0;
    }
  }

  for(int i = 0; i < w.size(); i++) {
    pii c = w[i];
    if(is_win(c)) {
      cout << 2 << '\n';
      cout << c.first + 1 << ' ' << c.second + 1;
      return 0;
    }
  }

  cout << 0;
}