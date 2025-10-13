#include <iostream>
#define INF 20000000
#define CPU_MAX 1000
#define PRIORITY_MAX 500

using namespace std;

int cpu[101], memory[101], priority[101], dp[501][1002], n, m, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> cpu[i] >> memory[i] >> priority[i];
  }

  for(int i = 0; i < 501; i++) for(int j = 0; j < 1002; j++) dp[i][j] = -INF;
  dp[0][0] = 0;

  for(int idx = 0; idx < n; idx++) {
    for(int i = PRIORITY_MAX; i >= 0; i--) {
      if(i + priority[idx] > PRIORITY_MAX) continue;
      int newI = i + priority[idx];

      for(int j = CPU_MAX + 1; j >= 0; j--) {
        int newJ = j + cpu[idx];

        if(newJ > CPU_MAX) {
          if(dp[newI][CPU_MAX + 1] == dp[i][j] && dp[i][j] == -INF) continue;
          dp[newI][CPU_MAX + 1] = max(dp[newI][CPU_MAX + 1], dp[i][j] + memory[idx]);
        } else {
          if(dp[newI][newJ] == dp[i][j] && dp[i][j] == -INF) continue;
          dp[newI][newJ] = max(dp[newI][newJ], dp[i][j] + memory[idx]);
        }
      }
    }
  }

  int ans = INF;
  for(int i = PRIORITY_MAX; i >= 0; i--) {
    for(int j = CPU_MAX + 1; j >= 0; j--) {
      if(j > CPU_MAX) {
        if(dp[i][j] >= k) {
          ans = i;
        }
      } else {
        if(j >= m && dp[i][j] >= k) {
          ans = i;
        }
      }
    }
  }

  if(ans == INF) cout << -1;
  else cout << ans;
}