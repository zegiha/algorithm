#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int>> arr;
vector <int> price;

int n, dp[10'001][2], ans;

vector <bool> visit;
void dfs(int node) {
  visit[node] = true;
  dp[node][0] = 0;
  dp[node][1] = price[node];

  for(int child : arr[node]) {
    if(!visit[child]) {
      dfs(child);

      dp[node][0] += max(dp[child][0], dp[child][1]);
      dp[node][1] += dp[child][0];
    }
  }
}

int main() {
  cin >> n;
  price.resize(n); arr.resize(n, vector <int> (0)); visit.resize(n, false);
  for(int i = 0; i < n; i++) {
    cin >> price[i];
    dp[i][0] = dp[i][1] = -1;
  }
  for(int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b; a--; b--;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  dfs(0);

  ans = max(dp[0][0], dp[0][1]);

  cout << ans; 
}