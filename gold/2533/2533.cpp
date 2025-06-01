#include <iostream>
#include <vector>

using namespace std;

int n, dp[1'000'001][2];
vector <vector <int>> arr;

vector <bool> visited;
void dfs(int node) {
  visited[node] = true;
  dp[node][0] = 0;
  dp[node][1] = 1;

  for(auto next : arr[node]) {
    if(visited[next]) continue;
    dfs(next);
    dp[node][0] += dp[next][1];
    dp[node][1] += min(dp[next][1], dp[next][0]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int a, b;
  arr.resize(n + 2, vector <int> (0));
  visited.resize(n + 2, false);
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  dfs(1);

  cout << min(dp[1][0], dp[1][1]);
}