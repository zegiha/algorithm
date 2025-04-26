#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;

int n, m, maxHeight;
int depth[40'002];
pii parent[40'002][16];
vector <vector <pii>> arr;

void input() {
  cin >> n;

  arr.resize(n + 2, vector <pii> (0));

  int a, b, c;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b >> c;
    arr[a].push_back({b, c});
    arr[b].push_back({a, c});
  }
}

void initParent() {
  int d = 1;
  queue <int> q;
  vector <bool> visit(n + 2, false);

  q.push(1);
  visit[1] = true;
  depth[1] = d;

  while(!q.empty()) {
    int size = q.size();
    d++;
    while(size--) {
      int node = q.front();
      q.pop();
      for(int i = 0; i < arr[node].size(); i++) {
        if(!visit[arr[node][i].first]) {
          parent[arr[node][i].first][0] = {node, arr[node][i].second};
          depth[arr[node][i].first] = d;
          visit[arr[node][i].first] = true;
          q.push(arr[node][i].first);
        }
      }
    }
  }

  int t = n;
  while(t) {
    t = t >> 1;
    maxHeight++;
  }

  for(int i = 1; i <= maxHeight; i++) {
    for(int j = 2; j <= n; j++) {
      parent[j][i] = {parent[parent[j][i-1].first][i-1].first, };
    }
  }
}

int solve(int a, int b) {
  int ans = 0;

  if(depth[a] != depth[b]) {
    if(depth[a] < depth[b]) {
      int t = a;
      a = b;
      b = t;
    }
    int diff = depth[a] - depth[b];
    for(int i = 0; 0 < diff; i++) {
      if(diff % 2 == 1) a = parent[a][i].first;
      diff = diff >> 1;
    }
  }
  // cout << "depthing done" << "\n"

  if(a != b) {
    while(parent[a].first != parent[b].first) {
      ans += parent[a].second + parent[b].second;
      a = parent[a].first;
      b = parent[b].first;
    }
    ans += parent[a].second + parent[b].second;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  input();
  initParent();
  cin >> m;
  while(m--) {
    int a, b; cin >> a >> b;
    cout << solve(a, b) << '\n';
  }
}