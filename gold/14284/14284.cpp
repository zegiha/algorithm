#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair <int, int>;

int main() {
  int n, d; cin >> n >> d;
  vector <vector <pii>> arr(n + 1);
  vector <int> dist(n + 1, -1);
  int a, b, c;
  for(int i = 0; i < d; i++) {
    cin >> a >> b >> c;
    arr[a].push_back({c, b});
    arr[b].push_back({c, a});
  }
  int s, t;
  cin >> s >> t;

  priority_queue <pii, vector<pii>, greater<pii>> q;
  q.push({0, s});
  dist[s] = 0;
  while(!q.empty()) {
    pii item = q.top(); q.pop();
    if(dist[item.second] != -1 && item.first > dist[item.second]) continue;

    int newDist, arrSecond;
    for(int i = 0; i < arr[item.second].size(); i++) {
      newDist = arr[item.second][i].first + item.first;
      arrSecond = arr[item.second][i].second;
      if(newDist < dist[arrSecond] || dist[arrSecond] == -1) {
        q.push({newDist, arrSecond});
        dist[arrSecond] = newDist;
      }
    }
  }

  cout << dist[t];
}
