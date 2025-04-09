#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
using pii = pair <int, int>;
using vvpii = vector <vector <pii>>;

int n, m, s, d, ans = INT_MAX;
vvpii arr;

void input() {
  int u, v, p;
  arr.resize(n, vector <pii> (0));
  for(int i = 0; i < m; i++) {
    cin >> u >> v >> p;
    arr[u].push_back({p, v});
  }
}

int getMinDist() {
  priority_queue <pii, vector <pii>, greater<pii>> q;
  vector <int> dist(n, -1);
  int res = INT_MAX;

  dist[s] = 0;
  q.push({0, s});

  while(!q.empty()) {
    int node = q.top().second, value = q.top().first;
    q.pop();

    if(dist[node] != -1 && dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      int newNode = arr[node][i].second, newValue = value + arr[node][i].first;
      if(dist[newNode] == -1 || newValue < dist[newNode]) {
        dist[newNode] = newValue;
        q.push({newValue, newNode});
      }
    }
  }

  return dist[d];
}

vector <bool> visited(n, false);
void setAlmostMinDist(int minDist, int node, int value) {
  if(node == d && minDist < value) ans = min(value, ans);
  for(int i = 0; i < arr[node].size(); i++) {
    if(!visited[arr[node][i].second]) {
      visited[arr[node][i].second] = true;
      setAlmostMinDist(minDist, arr[node][i].second, value + arr[node][i].first);
      visited[arr[node][i].second] = false;
    }
  }
}

void solve() {
  setAlmostMinDist(getMinDist(), s, 0);
  if(ans != INT_MAX) cout << ans << '\n';
  else cout << -1 << '\n';
}

int main() {
  cin >> n >> m;
  while(true) {
    cin >> s >> d;
    if(s == 0 && d == 0) break;

    input();
    solve();
    
    arr.clear();
    visited.clear();
    ans = INT_MAX;
  }
}