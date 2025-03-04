#include <iostream>
#include <queue>

using namespace std;
using pii = pair <int, int>;

int arr[12][6];

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool is_area(int r, int c) {
  return 0 <= r && r < 12 && 0 <= c && c < 6;
}

int main() {
  for(int i = 0; i < 12; i++) {
    string s; cin >> s;
    for(int j = 0; j < 6; j++) {
      if(s[j] == '.') arr[i][j] = 0;
      if(s[j] == 'R') arr[i][j] = 1;
      if(s[j] == 'G') arr[i][j] = 2;
      if(s[j] == 'B') arr[i][j] = 3;
      if(s[j] == 'P') arr[i][j] = 4;
      if(s[j] == 'Y') arr[i][j] = 5;
    }
  }

  int ans = 0;

  while(true) {
    bool sw = true, visit[12][6] = {0, };

    for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 6; j++) {
        if(!visit[i][j] && arr[i][j] != 0) {
          int root_v = arr[i][j];
          vector <pii> cdn(0);
          queue <pii> q;

          q.push({i, j});
          cdn.push_back({i, j});
          visit[i][j] = true;

          while(!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++) {
              int nr = r + dy[d], nc = c + dx[d];
              if(is_area(nr, nc) && !visit[nr][nc] && arr[nr][nc] == root_v) {
                q.push({nr, nc});
                visit[nr][nc] = true;
                cdn.push_back({nr, nc});
              }
            }
          }
          if(cdn.size() > 3) {
            for(pii c : cdn) {
              arr[c.first][c.second] = 0;
            }

            bool check[6] = {0, };
            for(pii i : cdn) {
              if(!check[i.second]) {
                check[i.second] = true;
                int r = i.first, c = i.second;
                while(r < 11 && arr[r + 1][c] == 0) r++;

                for(int i = r-1; i >= 0; i--) {
                  if(arr[i][c] != 0) {
                    arr[r][c] = arr[i][c];
                    arr[i][c] = 0;
                    r--;
                  }
                }
              }
            }

            // for(int i = 0; i < 12; i++) {
            //   for(int j = 0; j < 6; j++) {
            //     cout << arr[i][j] << ' ';
            //   }
            //   cout << '\n';
            // }

            ans++;
            sw = false;
            break;
          }
        }
        if(!sw) break;
      }
      if(!sw) break;
    }

    if(sw) break;
  }

  cout << ans;
}