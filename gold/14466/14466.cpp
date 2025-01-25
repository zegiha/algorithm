#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, r, arr[101][101][4], ans, cow_map[101][101]; // u d l r
vector <pair <int, int>> cows;
const int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

void input() {
  int t, r1, r2, c1, c2; cin >> n >> k >> t;
  while(t--) {
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    if(c1 == c2) {
      if(r1 > r2) {
        arr[r1][c1][0] = 1;
        arr[r2][c2][1] = 1;
      } else {
        arr[r1][c1][1] = 1;
        arr[r2][c2][0] = 1;
      }
    } else {
      if(c1 > c2) {
        arr[r1][c1][2] = 1;
        arr[r2][c2][3] = 1;
      } else {
        arr[r1][c1][3] = 1;
        arr[r2][c2][2] = 1;
      }
    }
  }
  int r, c;
  for(int i = 0; i < k; i++) {
    cin >> r >> c;
    r--; c--;
    cow_map[r][c] = i + 1;
    cows.push_back({r, c});
  }
}

bool is_area(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < n;
}

int get_cannot_go(int idx) {
  int
  now_cow = cow_map[cows[idx].first][cows[idx].second],
  res = 0;
  queue <pair <int ,int>> q;
  bool visit[101][101] = {0, };

  q.push(cows[idx]);
  visit[cows[idx].first][cows[idx].second] = true;

  while(!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nr = r + dy[i], nc = c + dx[i];
      if(is_area(nr, nc) && !visit[nr][nc] && arr[r][c][i] == 0) {
        q.push({nr, nc});
        visit[nr][nc] = true;
        if(cow_map[nr][nc] > now_cow) res++;
      }
    }
  }

  return res;
}

int main() {
  input();

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) cout << cow_map[i][j] << ' ';
  //   cout << '\n';
  // } cout << '\n';

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     for(int d = 0; d < 4; d++) {
  //       cout << arr[i][j][d] << ' ';
  //     } cout << "    ";
  //   }cout << '\n';
  // }cout << '\n';

  for(int i = 0; i < k - 1; i++) {
    ans += (k - 1 - i) - get_cannot_go(i);
  }
  cout << ans;
}

// #include <iostream>
// #include <queue>

// using namespace std;

// int arr[101][101][4], n, cow_map[101][101]; // u d r l
// pair <int, int> cows[101];
// const int dy[] = {-1, 1, 0, 0}, dx[]={0, 0, 1, -1};

// bool is_area(int r, int c) {
//   return 0 <= r && r < n && 0 <= c && c < n;
// }

// int get_cannot_reached(int cow_idx) {
//   int res = 0;
//   queue <pair <int, int>> q;
//   bool visit[101][101] = {0, };
  
//   q.push(cows[cow_idx]);
//   visit[cows[cow_idx].first][cows[cow_idx].second] = true;

//   while(!q.empty()) {
//     int r = q.front().first, c = q.front().second;
//     q.pop();

//     // cout << r << ' ' << c << '\n';

//     for(int d = 0; d < 4; d++) {
//       int nr = r + dy[d], nc = c + dx[d];
//       if(is_area(nr, nc) && !visit[nr][nc] && !arr[r][c][d]) {
//         q.push({nr, nc});
//         visit[nr][nc] = true;
//         if(cow_map[nr][nc] > cow_idx + 1) {
//           res++;
//         }
//       }
//     }
//   }

//   // for(int i = 0; i < n; i++) {
//   //   for(int j = 0; j < n; j++) {
//   //     cout << visit[i][j] ? "O " : "X ";
//   //   }
//   //   cout << '\n';
//   // }

//   return res;
// }

// int main() {
//   int k, r, c, ans = 0;
//   cin >> n >> k >> r;
//   for(int i = 0; i < r; i++) {
//     int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
//     r1--; r2--; c1--; c2--;
//     if(c1 == c2) {
//       if(r1 > r2) {
//         arr[r1][c1][1] = 1;
//         arr[r2][c2][0] = 1;
//       }
//       else {
//         arr[r1][c1][0] = 1;
//         arr[r2][c2][1] = 1;
//       }
//     } else {
//       if(c1 > c2) {
//         arr[r1][c1][3] = 1;
//         arr[r2][c2][2] = 1;
//       }
//       else {
//         arr[r1][c1][2] = 1;
//         arr[r2][c2][3] = 1;
//       }
//     }
//   }

//   for(int i = 0; i < k; i++) {
//     cin >> cows[i].first >> cows[i].second;
//     cows[i].first--; cows[i].second--;
//     cow_map[cows[i].first][cows[i].second] = i + 1;
//   }

//   for(int i = 0; i < k; i++) {
//     ans += get_cannot_reached(i);
//     // cout << "=================next================\n\n\n\n\n";
//   }

//   cout << ans;
// }