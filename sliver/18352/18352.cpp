#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, targetDis, startNode;
vector <vector <int>> arr;

void solve() {
  vector <int> ans;
  vector <bool> visit(n, false);
  queue<int> q;
  
  q.push(startNode);
  visit[startNode] = true;

  int nowDis = 0;
  while(!q.empty()) {
    int size = q.size();
    nowDis++;
    while(size--) {
      int node = q.front(); q.pop();
      if(!arr[node].empty()) for(int i = 0; i < arr[node].size(); i++) {
        if(!visit[arr[node][i]]) {
          q.push(arr[node][i]);
          visit[arr[node][i]] = true;
          if(nowDis == targetDis) ans.push_back(arr[node][i]);
        }
      }
    }
    if(nowDis == targetDis) break;
  }

  if(!ans.empty()) {
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << '\n';
    }
  } else {
    cout << -1;
  }
}

int main() {
  cin >> n >> m >> targetDis >> startNode;
  arr.resize(n + 1);
  while(m--) {
    int a, b; cin >> a >> b;
    arr[a].push_back(b);
  }

  solve();
}