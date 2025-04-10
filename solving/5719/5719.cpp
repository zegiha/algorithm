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

  cin >> s >> d;
  for(int i = 0; i < m; i++) {
    cin >> u >> v >> p;
    arr[u].push_back({p, v});
  }
}

int getMinDist() {
  priority_queue <pii, vector <pii>, greater<pii>> q;
  vector <int> dist(n, -1);

  dist[s] = 0;
  q.push({0, s});

  while(!q.empty()) {
    int node = q.top().second, value = q.top().first;
    q.pop();

    if(dist[node] != -1 && dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      if(arr[node][i].second == -1) continue;
      int newNode = arr[node][i].second, newValue = value + arr[node][i].first;
      if(dist[newNode] == -1 || newValue < dist[newNode]) {
        dist[newNode] = newValue;
        q.push({newValue, newNode});
      }
    }
  }

  return dist[d];
}

void deleteMinDist(int minDist) {
  
}

void solve() {
  int minDist = getMinDist();
  deleteMinDist(minDist);
  ans = getMinDist();
  cout << "=========";
  if(ans != minDist) cout << ans << '\n';
  else cout << -1 << '\n';
}

int main() {
  while(true) {
    cin >> n >> m;
    if(n == 0 && m == 0) break;

    input();
    solve();
    
    arr.clear();
    ans = INT_MAX;
  }
}