#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<vector<int>> arr;
vector <bool> visit;

void bfs(int st) {
  queue <int> q;
  q.push(st);
  visit[st] = true;
  while(!q.empty()) {
    int h = q.front();
    q.pop();
    for(int i = 0; i < arr[h].size(); i++) {
      if(!visit[arr[h][i]]) {
        visit[arr[h][i]] = true;
        q.push(arr[h][i]);
      }
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  arr.resize(n + 1);
  visit.resize(n + 1);
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(!visit[i]) {
      bfs(i);
      ans++;
    }
  }
  cout << ans;
}