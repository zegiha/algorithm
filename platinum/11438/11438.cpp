#include <iostream>
#include <vector>

using namespace std;

int n, p[100'001][18], d[100'001], maxHeight;
vector <vector <int>> arr;

void makeTree(int node, int parent, int depth) {
  p[node][0] = parent;
  d[node] = depth;

  for(int i = 0; i < arr[node].size(); i++) {
    if(arr[node][i] != parent) {
      makeTree(arr[node][i], node, depth + 1);
    }
  }
}

int LCA(int node1, int node2) {
  if(d[node1] != d[node2]) {
    if(d[node1] < d[node2]) {
      int t = node1;
      node1 = node2;
      node2 = t;
    }

    int dif = d[node1] - d[node2];
    for(int i = 0; 0 < dif; i++) {
      if(dif % 2 == 1) node1 = p[node1][i];
      dif = dif >> 1;
    }
  }

  if(node1 != node2) {
    for(int i = maxHeight; i >= 0; i--) {
      if(p[node1][i] != 0 && p[node1][i] != p[node2][i]) {
        node1 = p[node1][i];
        node2 = p[node2][i];
      }
    }
    node1 = p[node1][0];
  }
  return node1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  arr.resize(n+1, vector <int> (0));
  for(int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  makeTree(1, 0, 0);

  int tmp = n, cnt = 0;
  while(tmp > 1) {
    tmp = tmp >> 1;
    cnt++;
  }
  maxHeight = cnt;

  for(int k = 1; k <= maxHeight; k++) {
    for(int i = 2; i <= n; i++) {
      if(p[i][k-1] == 0) continue;
      p[i][k] = p[p[i][k-1]][k-1];
    }
  }

  int t; cin >> t;
  while(t--) {
    int ti, tii; cin >> ti >> tii;
    cout << LCA(ti, tii) << '\n';
  }
}