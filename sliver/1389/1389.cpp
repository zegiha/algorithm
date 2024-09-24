#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
pair <int, int> ans ={2'100'000'000, -1};
vector <vector <int>> arr;

int getNewAns(int idx) {
  int res = 0, depth = 0;
  queue <int> q;
  vector <bool> visit (n + 1, false);
  q.push(idx);
  visit[idx] = true;
  while(!q.empty()) {
    int size = q.size(), cnt = 0;
    depth++;
    while(size--) {
      int f = q.front(); q.pop();
      for(int i = 0; i < arr[f].size(); i++) {
        if(!visit[arr[f][i]]) {
          visit[arr[f][i]] = true;
          q.push(arr[f][i]);
          cnt++;
        }
      }
    }
    res += depth * cnt;
  }
  return res;
}

int main() {
  int t, a, b;
  cin >> n >> t;
  arr.resize(n + 1);
  while(t--) {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  
  for(int i = 1; i <= n; i++) {
    int newAns = getNewAns(i);
    if(newAns < ans.first) {
      ans = {newAns, i};
    }   
  }

  cout << ans.second;
}