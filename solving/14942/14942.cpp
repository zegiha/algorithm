#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, cost[100'001];
pair <int, int> table[100'001][18];
vector <vector <pair <int, int>>> arr;

void init_table() {
  queue <int> q;
  vector <bool> v (n+1, false);

  q.push(1);
  v[1] = true;

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(int i = 0; i < arr[node].size(); i++) {
      int new_node = arr[node][i].first, cost = arr[node][i].second;
      if(!v[new_node]) {
        q.push(new_node);
        v[new_node] = true;
        table[new_node][0] = {node, cost};
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << table[i][0].first << ' ' << table[i][0].second << '\n';
  }

  for(int j = 1; j < 18; j++) {
    for(int i = 1; i <= n; i++) {
      if(table[i][j-1].first == 0) continue;
      int
      new_node = table[table[i][j-1].first][j-1].first,
      new_cost = table[i][j-1].second + table[table[i][j-1].first][j-1].second;
      table[i][j] = {new_node, new_cost};
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << table[i][0].first << ' ' << table[i][0].second << '\n';
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> cost[i];

  arr.resize(n + 1, vector <pair <int, int>> (0));
  int a, b, c;
  for(int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    arr[a].push_back({b, c});
    arr[b].push_back({a, c});
  }

  init_table();

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 17; j++) {
      cout << table[i][j].first << ' ' << table[i][j].second << "  ||  ";
    }
    cout << '\n';
  }
}