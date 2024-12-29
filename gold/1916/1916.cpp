#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int n, m;
vector <vector <pii>> arr;

int main() {
  cin >> n >> m;

  arr.resize(n + 1);
  
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    arr[a].push_back({b, c});
  }

  int start, end; cin >> start >> end;

  priority_queue <pii, vector <pii>, greater <pii>> q;
  vector <int> dist (n+1, -1);

  q.push({start, 0});
  dist[start] = 0;
  while(!q.empty()) {
    int node = q.top().first, value = q.top().second;
    q.pop();
    if(dist[node] != -1 && dist[node] < value) continue;

    int new_value, new_node;
    for(int i = 0; i < arr[node].size(); i++) {
      new_value = value + arr[node][i].second;
      new_node = arr[node][i].first;
      if(dist[new_node] == -1) {
        q.push({new_node, new_value});
        dist[new_node] = new_value;
      } else if(dist[new_node] > new_value) {
        q.push({new_node, new_value});
        dist[new_node] = new_value;
      }
    }
  }

  cout << dist[end];
}