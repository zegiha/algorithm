#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;

int n, m, s, d;
vector <vector <pii>> arr;

vector <vector <int>> getDist() {
  priority_queue <pii, vector <pii>, greater <pii>> q;
  vector <int> dist(n, -1);
  vector <vector <int>> res(n);

  q.push({0, s});
  dist[s] = 0;

  while(!q.empty()) {
    int node = q.top().second, value = q.top().first;
    q.pop();

    if(dist[node] != -1 && dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      int newNode = arr[node][i].second, newValue = arr[node][i].first + value;
      if(dist[newNode] == -1 || newValue < dist[newNode]) {
        dist[newNode] = newValue;
        q.push({newValue, newNode});

        res[newNode].clear();
        res[newNode].push_back(node);
      } else if(dist[newNode] == newValue) res[newNode].push_back(node);
    }
  }

  return res;
}

void deleteDist(vector <vector<int>> dist, int now) {
  if(now == s) return;

  for(int i = 0; i < dist[now].size(); i++) {
    int next = dist[now][i];
    for(int i = 0; i < arr[next].size(); i++) {
      if(arr[next][i].second == now) arr[next][i] = {-1, -1};
    }
    deleteDist(dist, next);
  }
  
  // queue <int> q;
  // vector <bool> visited(n, false);

  // q.push(d);
  // visited[d] = true;

  // for(int i = 0; i < dist.size(); i++) {
  //   cout << i << " : ";
  //   for(int j = 0; j < dist[i].size(); j++) {
  //     cout << dist[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // while(!q.empty()) {
  //   int node = q.front();
  //   q.pop();

  //   for(int i = 0; i < dist[node].size(); i++) {
  //     int newNode = dist[node][i];

  //     if(visited[newNode]) continue;

  //     for(int j = 0; j < arr[newNode].size(); j++) {
  //       if(arr[newNode][j].second == node) {
  //         arr[newNode][j] = {-1, -1};
  //       }
  //     }

  //     q.push(newNode);
  //     visited[newNode] = true;
  //   }
  // }
}

int getAns() {
  priority_queue <pii, vector <pii>, greater <pii>> q;
  vector <int> dist(n, -1);

  q.push({0, s});
  dist[s] = 0;

  while(!q.empty()) {
    int node = q.top().second, value = q.top().first;
    q.pop();

    if(dist[node] != -1 && dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      if(arr[node][i].second == -1) continue;

      int newNode = arr[node][i].second, newValue = arr[node][i].first + value;
      if(dist[newNode] == -1 || newValue < dist[newNode]) {
        dist[newNode] = newValue;
        q.push({newValue, newNode});
      }
    }
  }

  return dist[d];
}

int main() {
  while(true) {
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    cin >> s >> d;

    arr.resize(n, vector <pii> (0));
    for(int i = 0; i < m; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      arr[u].push_back({p, v});
    }

    deleteDist(getDist(), d);
    cout << getAns() << '\n';

    arr.clear();
  }
}