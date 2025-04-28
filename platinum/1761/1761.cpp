#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int
n, maxHeight,
parent[40'010][17],
dist[40'010][17],
depth[40'010];
vector <vector <pair <int, int>>> arr;

void initParent() {
  int depthCnt = 1;
  queue <int> q;
  vector <bool> visited(n + 2);
  q.push(1);
  visited[1] = true;
  depth[1] = depthCnt;
  while(!q.empty()) {
    depthCnt++;
    int size = q.size();
    while(size--) {
      int node = q.front();
      q.pop();
      for(int i = 0; i < arr[node].size(); i++) {
        if(!visited[arr[node][i].first]) {
          visited[arr[node][i].first] = true;
          q.push(arr[node][i].first);
          parent[arr[node][i].first][0] = node;
          dist[arr[node][i].first][0] = arr[node][i].second;
          depth[arr[node][i].first] = depthCnt;
        }
      }
    }
  }

  int tmp = n;
  while(tmp) {
    tmp = tmp >> 1;
    maxHeight++;
  }

  for(int j = 1; j <= maxHeight; j++) {
    for(int i = 1; i <= n; i++) {
      parent[i][j] = parent[parent[i][j-1]][j-1];
      dist[i][j] = dist[parent[i][j-1]][j-1] + dist[i][j-1];
    }
  }
}

int LCA(int a, int b) {
  int res = 0;

  if(depth[a] != depth[b]) {
    if(depth[a] < depth[b]) {
      int t = a;
      a = b;
      b = t;
    }

    int diff = depth[a] - depth[b];
    for(int i = 0; 0 < diff; i++) {
      if(diff % 2 != 0) {
        res += dist[a][i];
        a = parent[a][i];
      }
      diff = diff >> 1;
    }
  }

  if(a != b) {
    for(int i = maxHeight; i >= 0; i--) {
      if(parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
        res += dist[a][i] + dist[b][i];
        a = parent[a][i];
        b = parent[b][i];
      }
    }
    res += dist[a][0] + dist[b][0];
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  arr.resize(n + 2, vector <pair<int, int>> (0));

  int a, b, c;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b >> c;
    arr[a].push_back({b, c});
    arr[b].push_back({a, c});
  }

  initParent();

  int t; cin >> t;
  while(t--) {
    cin >> a >> b;
    cout << LCA(a, b) << '\n';
  }
}