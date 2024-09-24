#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector <vector <int>> arr;
vector <int> ans;

void solve() {
  ans.resize(n + 1);
  queue <int> q;
  vector <int> visit(n + 1);
  visit[1] = true;
  q.push(1);
  while(!q.empty()) {
    int f = q.front(); q.pop();
    for(int i = 0; i < arr[f].size(); i++) {
      if(!visit[arr[f][i]]) {
        visit[arr[f][i]] = true;
        q.push(arr[f][i]);
        ans[arr[f][i]] = f;
      }
    }
  }
}

int main() {
  cin >> n; arr.resize(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  solve();
  for(int i = 2; i <= n; i++) cout << ans[i] << '\n';
}