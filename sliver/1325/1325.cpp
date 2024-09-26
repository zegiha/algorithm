#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <vector <int>> arr;
pair <int, vector <int>> ans = {-1, vector <int> (0)};

int getHack(int idx) {
  int res = 0;
  queue <int> q;
  vector <bool> visit (n + 1);
  q.push(idx);
  visit[idx] = true;

  while(!q.empty()) {
    int f = q.front(); q.pop();
    for(int i = 0; i < arr[f].size(); i++) {
      if(!visit[arr[f][i]]) {
        visit[arr[f][i]] = true;
        q.push(arr[f][i]);
        res++;
      }
    }
  }
  
  return res;
}

int main() {
  cin >> n >> m; arr.resize(n + 1);
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    arr[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    int canHack = getHack(i);
    // cout << i << " : " << canHack << '\n';
    if(ans.first == canHack) ans.second.push_back(i);
    else if(ans.first < canHack) ans = {canHack, vector <int> (1, i)};
  }
  
  sort(ans.second.begin(), ans.second.end());
  for(int i = 0; i < ans.second.size(); i++) cout << ans.second[i] << ' ';
}