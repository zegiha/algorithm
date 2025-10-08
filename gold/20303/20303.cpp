#include <iostream>
#include <vector>

using namespace std;

using pii = pair <int, int>;

int n, m, k, parent[30'002][2], childCnt[30'002], dpPrev[3'001], dpNext[3'001];
vector <pii> arr;

int Find(int node) {
  if(parent[node][0] == 0) return node;
  return parent[node][0] = Find(parent[node][0]);
}

void Union(int a, int b) {
  int aRoot = Find(a), bRoot = Find(b);

  if(aRoot == bRoot) return;

  parent[bRoot][0] = aRoot;
  parent[aRoot][1] += parent[bRoot][1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

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
    for(int j = k-1; j > 0; j--) {
      if(j >= arr[i-1].second) {
        dpNext[j] = max(dpPrev[j], dpPrev[j - arr[i-1].second] + arr[i-1].first);
      } else {
        dpNext[j] = dpPrev[j];
      }
    }
    for(int j = k-1; j > 0; j--) {
      dpPrev[j] = dpNext[j];
      dpNext[j] = 0;
    }
  }

  cout << dpPrev[k-1];
}