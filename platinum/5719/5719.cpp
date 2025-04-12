#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;

int n, m, s, d;
vector <vector <pii>> arr;
vector <int> w[501];
bool visited[501] = {0, };
priority_queue <pii, vector <pii>, greater <pii>> pq;
int dist[501];
queue <int> q;

void setW() {
  for(int i = 0; i < n; i++) dist[i] = -1;

  pq.push({0, s});
  dist[s] = 0;

  while(!pq.empty()) {
    int node = pq.top().second, value = pq.top().first;
    pq.pop();

    if(dist[node] != -1 && dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      int newNode = arr[node][i].second, newValue = arr[node][i].first + value;
      if(dist[newNode] == -1 || newValue < dist[newNode]) {
        dist[newNode] = newValue;
        pq.push({newValue, newNode});

        w[newNode].clear();
        w[newNode].push_back(node);
      } else if(dist[newNode] == newValue) w[newNode].push_back(node);
    }
  }

}

void deleteDist() {
  setW();
  q.push(d);

  // for(int i = 0; i < n; i++) {
  //   cout << i << " : ";
  //   for(int j = 0; j < w[i].size(); j++) {
  //     cout << w[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(int i = 0; i < w[node].size(); i++) {
      int newNode = w[node][i];

      for(int j = 0; j < arr[newNode].size(); j++) {
        if(arr[newNode][j].second == node) {
          arr[newNode][j] = {-1, -1};
        }
      }
      if(!visited[newNode]) {
        q.push(newNode);
        visited[newNode] = true;
      }
    }
  }
}

int getAns() {
  for(int i = 0; i < n; i++) dist[i] = -1;

  pq.push({0, s});
  dist[s] = 0;

  while(!pq.empty()) {
    int node = pq.top().second, value = pq.top().first;
    pq.pop();

    if(dist[node] != -1 && dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      if(arr[node][i].second == -1) continue;

      int newNode = arr[node][i].second, newValue = arr[node][i].first + value;
      if(dist[newNode] == -1 || newValue < dist[newNode]) {
        dist[newNode] = newValue;
        pq.push({newValue, newNode});
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

    arr.resize(n);
    for(int i = 0; i < m; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      arr[u].push_back({p, v});
    }

    deleteDist();
    // cout << "============";
    cout << getAns() << '\n';

    arr.clear();
    for(int i = 0; i < 501; i++) {
      w[i].clear();
      visited[i] = false;
    }
  }
}