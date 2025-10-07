#include <iostream>
#include <vector>

using namespace std;

using pii = pair <int, int>;

int n, m, k, parent[30'002][2], childCnt[30'002], dp[30'002][3'001];
vector <pii> arr;

int Find(int node) {
  if(parent[node][0] == 0) return node;
  return parent[node][0] = Find(parent[node][0]);
}

void Union(int a, int b) {
  int aRoot = Find(a), bRoot = Find(b);
  parent[bRoot][0] = aRoot;
  parent[aRoot][1] += parent[bRoot][1];
}

int main() {
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++) cin >> parent[i][1];

  while(m--) {
    int a, b; cin >> a >> b;
    Union(a, b);
  }

  int root;
  for(int i = 1; i <= n; i++) {
    root = Find(i);
    childCnt[root]++;
  }

  bool vis[30'002] = {0, };
  for(int i = 1; i <= n; i++) {
    root = Find(i);
    if(!vis[root]) {
      arr.push_back({parent[root][1], childCnt[root]});
      vis[root] = true;
    }
  }

  for(int i = 1; i <= arr.size(); i++) {
    for(int j = 1; j <= min(k, 3'000); j++) {
      if(arr[i-1].second > j) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], arr[i-1].first + dp[i-1][j - arr[i-1].second]);
    }
  }

  cout << dp[arr.size()][min(k, 3'000)];
}