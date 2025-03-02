#include <iostream>
#include <vector>

#define INF 9223372036854775807

using namespace std;
using pii = pair <int, int>;

int n, m;
long long dist[501];
vector <vector <pii>> arr;

int main() {
  cin >> n >> m;
  arr.resize(n+1, vector <pii> (0));
  for(int i = 1; i <= n; i++) dist[i] = INF;
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[a].push_back({b, c});
  }

  dist[1] = 0;
  for(int i = 0; i < n-1; i++) {
    for(int j = 1; j <= n; j++) {
      if(dist[j] == INF) continue;
      for(pii t : arr[j]) {
        dist[t.first] = min(dist[t.first], dist[j] + t.second);
      }
    }
  }
  
  bool sw = true;
  for(int j = 1; j <= n; j++) {
    if(dist[j] == INF) continue;
    for(pii t : arr[j]) {
      int prev = dist[t.first];
      dist[t.first] = min(dist[t.first], dist[j] + t.second);
      if(prev != dist[t.first]) {
        sw = false;
        break;
      }
    }
  }

  if(sw) {
    for(int i = 2; i <= n; i++) {
      if(dist[i] == INF) cout << -1 << '\n';
      else cout << dist[i] << '\n';
    }
  } else {
    cout << -1;
  }
}