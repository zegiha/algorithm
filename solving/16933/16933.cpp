#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
using tiiii = tuple <int, int, int, int>;

const int dy[] = {0, 0, 1, -1, 0}, dx[] = {1, -1, 0, 0, 0};

int n, m, k, arr[1001][1001], ans = 1;

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    for(int j = 0; j < m; j++) {
      arr[i][j] = t[j] - '0';
    }
  }

  int visit[2][1001][1001] = {0, }, sw = true;
  queue <tiiii> q;

  q.push({0, 1, 0, 0});
  visit[0][0][0] = 1;

  while(!q.empty() && sw) {
    int size = q.size();

    // cout << "----------------------\n";

    while(size--) {
      auto [isNight, breakCnt, row,  col] = q.front();
      q.pop();

      for(int d = 0; d < 5; d++) {
        int newRow = row + dy[d], newCol = col + dx[d];

        if(
          isArea(newRow, newCol) &&
          (visit[!isNight][newRow][newCol] == 0 || breakCnt <= visit[!isNight][newRow][newCol])
        ) {
          if(arr[newRow][newCol] == 1 && breakCnt-1 < k) {
            q.push({!isNight, breakCnt + 1, newRow, newCol});
            visit[!isNight][newRow][newCol] = breakCnt + 1;

            if(n-1 == newRow && m-1 == newCol) {sw = false; break;}
          } else if(arr[newRow][newCol] == 0) {
            q.push({!isNight, breakCnt, newRow, newCol});
            visit[!isNight][newRow][newCol] = breakCnt;

            if(n-1 == newRow && m-1 == newCol) {sw = false; break;}
          }
        }
      }
    }

    ans++;

    // cout << "----------------------\n";
  }


  if(n == 1 && m == 1) cout << 1;
  else if(!sw) cout << ans;
  else cout << -1;
}