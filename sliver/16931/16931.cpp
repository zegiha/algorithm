#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101], n, m, ans;

const int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int get_extent(int r, int c) {
  int nr, nc, res = 0;
  for(int d = 0; d < 4; d++) {
    nr = r + dy[d]; nc = c + dx[d];
    if(is_area(nr, nc)) {
      res += max(0, arr[r][c] - arr[nr][nc]);
    } else {
      res += arr[r][c];
    }
  }

  return res;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ans += 2 + get_extent(i, j);
    }
  }

  cout << ans;
}