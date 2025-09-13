#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair <int, int>;

int n, m, maxDist[10'001], startNode, endNode, usedRoad;
vector <vector <pii>> graph, reverseGraph;

void setMaxDist() {
  queue <pii> q;
  
  q.push({startNode, 0});

  while(!q.empty()) {
    int node = q.front().first, dist = q.front().second;
    q.pop();

    for(int i = 0; i < graph[node].size(); i++) {
      int newNode = graph[node][i].first, newDist = dist + graph[node][i].second;
      bool isVisit = maxDist[newNode] != 0;

      maxDist[newNode] = max(maxDist[newNode], newDist);
      if(!isVisit) q.push({newNode, newDist});
    }
  }
}

void setUsedRoad() {
  queue <int> q;
  bool check[10'001] = {0, };

  q.push(endNode);
  check[endNode] = true;

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(int i = 0; i < reverseGraph[node].size(); i++) {
      int newNode = reverseGraph[node][i].first, newDist = maxDist[node] - reverseGraph[node][i].second;

      if(newDist != maxDist[newNode]) continue;
      usedRoad++;

      if(check[newNode]) continue;
      q.push(newNode);
      check[newNode] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  graph.resize(n + 1, {});
  reverseGraph.resize(n + 1, {});

  int a, b, c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;

    graph[a].push_back({b, c});
    reverseGraph[b].push_back({a, c});
  }

  cin >> startNode >> endNode;

  setMaxDist();

  // for(int i = 1; i <= n; i++) cout << maxDist[i] << ' ';
  // cout << '\n';

  setUsedRoad();

  cout << maxDist[endNode] << '\n' << usedRoad;
}
