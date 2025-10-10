#include <iostream>

#define PRIORITY_MAX 500
#define CPU_MAX 1000
#define INF 2'100'000'000

using namespace std;

int priority[101], cpu[101], memory[101], N, M, K, dp[501][1002];

int main() {
  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) cin >> cpu[i] >> memory[i] >> priority[i];

  for(int i = 0; i < 501; i++) for(int j = 0; j < 1002; j++) dp[i][j] = -INF;
  dp[0][0] = 0;


  for(int idx = 0; idx < N; idx++) {
    for(int i = PRIORITY_MAX; i >= 0; i--) {
      if(i + priority[idx] > PRIORITY_MAX) continue;
      for(int j = CPU_MAX + 1; j >= 0; j--) {
        if(dp[i][j] == -INF) continue;
        dp[i + priority[idx]][min(j + cpu[idx], CPU_MAX + 1)] = max(dp[i + priority[idx]][min(j + cpu[idx], CPU_MAX + 1)], dp[i][j] + memory[idx]);
      }
    }
  }

  int ans = INF;
  for(int i = PRIORITY_MAX; i >= 0; i--) {
    for(int j = CPU_MAX; j >= 0; j--) {
      if(j >= M && dp[i][j] >= K && i < ans) {
        ans = i;
      }

      // cout << dp[i][j] << "\n";
    }
  }
  
  if(ans == INF) cout << -1;
  else cout << ans;
}