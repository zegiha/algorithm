#include <iostream>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int n, d[100'001], maxDepth = 0;
pii p[100'001][7];
vector <vector <pii>> arr;

void makeTree(int node, pii parent, int depth) {
  d[node] = depth;
  p[node][0] = parent;

  for(int i = 0; i < arr[node].size(); i++) {
    if(arr[node][i].first != parent.first) {
      makeTree(arr[node][i].first, {node, arr[node][i].second}, depth + 1);
    }
  }
}

void setMaxDepth() {
  int tmp = n, cnt = 0;

  while(tmp > 1) {
    tmp = tmp >> 1;
    cnt++;
  }

  maxDepth = cnt;
}

pii getAns(int a, int b) {
  pii ans = {1'000'001, -1};

  if(d[a] != d[b]) {
    if(d[a] > d[b]) {
      int t = a;
      a = b;
      b = a;
    }

    int dif = d[b] - d[a];

    for(int i = 0; dif > 0; i++) {
      if(dif % 2 == 1) {
        b = p[b][i].first;
        ans = {min(ans.first, p[b][i].second), max(ans.second, p[b][i].second)};
      }
      dif = dif >> 1;
    }
  }

  if(a != b) {
    pii newAns = {1'000'001, -1};
    for(int i = maxDepth; i >= 0; i--) {
      cout << p[a][i].first << ' ' << p[b][i].first << '\n';

      if(p[a][i].first != 0 && p[a][i].first != p[b][i].first) {
        a = p[a][i].first;
        b = p[b][i].first;
        newAns = {1'000'001, -1};
      }
      if(p[a][i].first != 0)
        newAns = {min({newAns.first, p[b][i].second, p[a][i].second}), max({newAns.second, p[b][i].second, p[a][i].second})};
    }

    if(p[a][0].first != 0)
      newAns = {min({newAns.first, p[b][0].second, p[a][0].second}), max({newAns.second, p[b][0].second, p[a][0].second})};

    ans = {
      min(ans.first, newAns.first),
      max(ans.second, newAns.second)
    };
  }

  return ans;
}

int main() {
  cin >> n;

  arr.resize(n + 1, {});

  int a, b, c;
  for(int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    arr[a].push_back({b, c});
    arr[b].push_back({a, c});
  }

  makeTree(1, {0, 0}, 0);
  
  setMaxDepth();

  for(int j = 1; j <= maxDepth; j++) {
    for(int i = 1; i <= n; i++) {
      p[i][j] = p[p[i][j-1].first][j-1];
    }
  }
  // cout << '\n';

  // for(int i = 0; i <= n; i++) {
  //   cout << i << " : ";
  //   for(int j = 0; j <= maxDepth; j++) cout << p[i][j].first << ", " << p[i][j].second << "  ||  ";
  //   cout << '\n';
  // }

  int t; cin >> t;
  pii ans;

  cout << '\n';
  
  while(t--) {
    cin >> a >> b;
    cout << "----------------------------------\n";
    ans = getAns(a, b);
    cout << "----------------------------------\n" << ans.first << ' ' << ans.second << '\n';
  }
}