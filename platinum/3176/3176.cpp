#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair <int, int>;

const int maxSize = 2'100'000'000;

int n, p[100'001][20], minRoad[100'001][20], maxRoad[100'001][20], d[100'001], maxDepth = 20;
vector <vector <pii>> arr;

void makeTree(int node, pii parent, int depth) {
  d[node] = depth;
  p[node][0] = parent.first;
  minRoad[node][0] = parent.second;
  maxRoad[node][0] = parent.second;

  for(int i = 0; i < arr[node].size(); i++) {
    if(arr[node][i].first != parent.first) {
      makeTree(arr[node][i].first, {node, arr[node][i].second}, depth + 1);
    }
  }
}

void setMaxDepth() {
  int t = n;
  while(t > 1) {
    t = t >> 1;
    maxDepth++;
  }
  maxDepth++;
}

pii getAns(int a, int b) {
  int minRes = maxSize, maxRes = maxSize * -1;

  if(d[a] != d[b]) {
    if(d[a] > d[b]) {
      int t = a;
      a = b;
      b = t;
    }

    int dif = d[b] - d[a];
    for(int i = 0; dif > 0; i++) {
      if(dif % 2 == 1) {
        minRes = min(minRes, minRoad[b][i]);
        maxRes = max(maxRes, maxRoad[b][i]);
        b = p[b][i];
      }
      dif = dif >> 1;
    }
  }

  if(a != b) {
    for(int i = maxDepth-1; i >= 0; i--) {
      // cout << a << ' ' << b << ' ' << i << '\n';
      if(p[a][i] != 0 && p[a][i] != p[b][i]) {
        minRes = min(minRes, minRoad[a][i]);
        minRes = min(minRes, minRoad[b][i]);

        maxRes = max(maxRes, maxRoad[a][i]);
        maxRes = max(maxRes, maxRoad[b][i]);

        a = p[a][i];
        b = p[b][i];
      }
    }


    minRes = min(minRes, minRoad[a][0]);
    minRes = min(minRes, minRoad[b][0]);

    maxRes = max(maxRes, maxRoad[a][0]);
    maxRes = max(maxRes, maxRoad[b][0]);
  }

  return {minRes, maxRes};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  arr.resize(n + 1, {});
  for(int i = 0; i < n-1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a].push_back({b, c});
    arr[b].push_back({a, c});
  }

  for(int i = 0; i < 100'001; i++) {
    for(int j = 0; j < 17; j++) {
      p[i][j] = 0;
      maxRoad[i][j] = maxSize * -1;
      minRoad[i][j] = maxSize;
    }
  }

  makeTree(1, {0, 0}, 0);
  // setMaxDepth();

  for(int j = 1; j < maxDepth; j++) {
    for(int i = 2; i <= n; i++) {
      if(p[i][j-1] != 0) {
        p[i][j] = p[p[i][j-1]][j-1];
        minRoad[i][j] = min(
          minRoad[i][j-1],
          minRoad[p[i][j-1]][j-1]
        );
        maxRoad[i][j] = max(
          maxRoad[i][j-1],
          maxRoad[p[i][j-1]][j-1]
        );
      }
    }
  }

  int t; cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    pii ans = getAns(a, b);
    cout << ans.first << ' ' << ans.second << '\n';
  }
}