#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, s, e;
vector <vector <int>> arr;

int main() {
  int t, a, b;
  cin >> n >> s >> e >> t;
  arr.resize(n + 1);
  while(t--) {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  int ans = 0;
  queue <int> q;
  vector <int> visit(n + 1, false);
  q.push(s);
  visit[s] = true;
  while(!q.empty()) {
    int size = q.size();
    ans++;
    while(size--) {
      int f = q.front(); q.pop();
      for(int i = 0; i < arr[f].size(); i++) {
        if(!visit[arr[f][i]]) {
          visit[arr[f][i]] = true;
          q.push(arr[f][i]);
          if(arr[f][i] == e) {
            cout << ans;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;
}