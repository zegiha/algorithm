#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, arr[1001][1001];
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    for(int j = 0; j < m; j++) {
      arr[i][j] = str[j] - '0';
    }
  }

  queue <pair <int, int>> q;
  bool visit[1001][1001] = {0, };

  for(int i = 0 ; i < m; i++) {
    if(arr[0][i] == 0 && !visit[0][i]) {
      q.push({0, i});
      visit[0][i];
      while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++) {
          int newR = r + dy[d], newC = c + dx[d];
          if(!isArea(newR, newC)) continue;
          if(arr[newR][newC] == 0 && !visit[newR][newC]) {
            q.push({newR, newC});
            visit[newR][newC] = 1;
            if(newR == n - 1) {
              cout << "YES";
              // cout << endl;
              // for(int i = 0; i < n; i++) {
              //   for(int j = 0; j < n; j++) {
              //     cout << visit[i][j] << ' ';
              //   }
              //   cout <<endl;
              // }
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "NO";
}