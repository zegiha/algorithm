#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s;
vector <vector <bool>> arr;
vector <bool> d, b;

void dfs(int e) {
  cout << e << ' ';
  d[e] = true;
  for(int i = 1; i <= n; i++) {
    if(!d[i] && arr[e][i]) {
      dfs(i);
    }
  }
}

void bfs() {
  queue <int> q;
  q.push(s);
  b[s] = true;
  while(!q.empty()) {
    int e = q.front(); q.pop();
    cout << e << ' ';
    for(int i = 1; i <= n; i++) {
      if(arr[e][i] && !b[i]) {
        q.push(i);
        b[i] = true;
      }
    }
  }
}

int main() {
  cin >> n >> m >> s;
  arr.resize(n + 2, vector <bool> (n + 2, false));
  d.resize(n + 2, false);
  b.resize(n + 2, false);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = true;
    arr[b][a] = true;
  }

  dfs(s); cout << endl;
  bfs();
}