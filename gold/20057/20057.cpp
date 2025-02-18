#include <iostream>

using namespace std;

int arr[500][500], n, ans;
const int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0}, rate[] = {1, 1, 7, 7, 2, 2, 10, 10, 5};

const pair <int, int> sand_d[2][10] = {
  {{1, 0}, {-1, 0}, {1, -1}, {-1, -1}, {2, -1}, {-2, -1}, {1, -2}, {-1, -2}, {0, -3}, {0, -2}}, // 좌, d = 0 기준
  {{0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}, {-3, 0}, {-2, 0}}, // 상, d = 3 기준
};

int get_rated(int n, int p) {
  return (n * p) / 100;
}

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < n;
}

void move_sand(int r, int c, int d) {
  int total = arr[r + dy[d]][c + dx[d]], total_minus = 0, tr, tc;
  arr[r + dy[d]][c + dx[d]] = 0;
  switch(d) {
    case 0:
      for(int i = 0; i < 9; i++) {
        tr = r + sand_d[0][i].first; tc = c + sand_d[0][i].second;
        if(is_area(tr, tc)) {
          arr[tr][tc] += get_rated(total, rate[i]);
        } else {
          ans += get_rated(total, rate[i]);
        }
        total_minus += get_rated(total, rate[i]);
      }
      tr = r + sand_d[0][9].first; tc = c + sand_d[0][9].second;
      if(is_area(tr, tc)) arr[tr][tc] += total - total_minus;
      else ans += total - total_minus;
      break;
    case 1:
      for(int i = 0; i < 9; i++) {
        tr = r + sand_d[1][i].first * -1; tc = c + sand_d[1][i].second;
        if(is_area(tr, tc)) {
          arr[tr][tc] += get_rated(total, rate[i]);
        } else {
          ans += get_rated(total, rate[i]);
        }
        total_minus += get_rated(total, rate[i]);
      }
      tr = r + sand_d[1][9].first * -1; tc = c + sand_d[1][9].second;
      if(is_area(tr, tc)) arr[tr][tc] += total - total_minus;
      else ans += total - total_minus;
      break;
    case 2:
      for(int i = 0; i < 9; i++) {
        tr = r + sand_d[0][i].first; tc = c + sand_d[0][i].second * -1;
        if(is_area(tr, tc)) {
          arr[tr][tc] += get_rated(total, rate[i]);
        } else {
          ans += get_rated(total, rate[i]);
        }
        total_minus += get_rated(total, rate[i]);
      }
      tr = r + sand_d[0][9].first; tc = c + sand_d[0][9].second * -1;
      if(is_area(tr, tc)) arr[tr][tc] += total - total_minus;
      else ans += total - total_minus;
      break;
    case 3:
      for(int i = 0; i < 9; i++) {
        tr = r + sand_d[1][i].first; tc = c + sand_d[1][i].second;
        if(is_area(tr, tc)) {
          arr[tr][tc] += get_rated(total, rate[i]);
        } else {
          ans += get_rated(total, rate[i]);
        }
        total_minus += get_rated(total, rate[i]);
      }
      tr = r + sand_d[1][9].first; tc = c + sand_d[1][9].second;
      if(is_area(tr, tc)) arr[tr][tc] += total - total_minus;
      else ans += total - total_minus;
      break;
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int r = n / 2, c = n / 2, dist = 1, d = 0, moved = 0;
  bool is_add_dist = false;
  while(!(r == 0 && c == 0)) {
    if(moved == dist) {
      moved = 0;
      d = (d + 1) % 4;
      if(is_add_dist) {
        is_add_dist = false;
        dist++;
      } else is_add_dist = true;
    }

    move_sand(r, c, d);

    r += dy[d]; c += dx[d];
    moved++;
  }

  cout << ans;

}