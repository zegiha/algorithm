#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

void solve() {
  int n, d, s;
  vector <vector <pair <int, int>>> arr;
  vector <int> dist;

  cin >> n >> d >> s;
  arr.resize(n + 1); dist.resize(n + 1, -1);
  int a, b, w;
  for(int i = 0; i < d; i++) {
    cin >> a >> b >> w;
    arr[b].push_back({w, a});
  }

  int totalSecond = 0, totalComputers = 1;
  priority_queue <pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  dist[s] = 0;
  while(!q.empty()) {
    pair <int, int> item = q.top(); q.pop();
    if(dist[item.second] != -1 && item.first > dist[item.second]) continue;

    int newDist;
    for(int i = 0; i < arr[item.second].size(); i++) {
      newDist = item.first + arr[item.second][i].first;
      if(dist[arr[item.second][i].second] == -1) {
        q.push({newDist, arr[item.second][i].second});
        dist[arr[item.second][i].second] = newDist;
        totalComputers++;
      } else if(newDist < dist[arr[item.second][i].second]) {
        q.push({newDist, arr[item.second][i].second});
        dist[arr[item.second][i].second] = newDist;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(totalSecond < dist[i]) {
      totalSecond = dist[i];
    }
  }

  cout << totalComputers << ' ' << totalSecond << '\n';
}

int main() {
  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}
