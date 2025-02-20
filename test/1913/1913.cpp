#include <iostream>

using namespace std;

int arr[1000][1000], n, coords;
pair <int, int> ans;
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void set_arr(int r, int c, int moved, int d, int dist, int cnt) {
  if(moved == 2) {
    moved = 0;
    dist++;
  }

  for(int i = 0; i < dist; i++) {
    r += dy[d]; c += dx[d];
    arr[r][c] = cnt++;
    if(r == 0 && c == 0) return;
  }

  set_arr(r, c, moved + 1, (d + 1) % 4, dist, cnt);
}

int main() {
  cin >> n >> coords;
  arr[n/2][n/2] = 1;
  set_arr(n / 2, n / 2, 0, 0, 1, 2);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << arr[i][j] << ' ';
      if(arr[i][j] == coords) ans = {i + 1, j + 1};
    }
    cout << '\n';
  }

  cout << ans.first << ' ' << ans.second;
}