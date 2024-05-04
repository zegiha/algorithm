#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector <vector <pair <int, int>>> arr;

pair <int, int> dfs(int root) {
  int ansIndex = root, ansSum = 0;
  stack <pair <int, int>> s;
  vector <bool> visit;
  visit.resize(n + 1);

  s.push(make_pair(root, 0));
  visit[root] = true;
  while(!s.empty()) {
    bool sw = true;
    int e = s.top().first, sum = s.top().second;
    s.pop();
    for(int i = 0; i < arr[e].size(); i++) {
      if(!visit[arr[e][i].first]) {
        s.push(make_pair(arr[e][i].first, sum + arr[e][i].second));
        visit[arr[e][i].first] = true;
        sw = false;
      }
    }
    if(sw) if(ansSum < sum) {
      ansIndex = e;
      ansSum = sum;
    }

    // for(int i = 1; i <= n; i++) {
    //   if(arr[e][i] != 0 && !visit[i]) {
    //     s.push(make_pair(i, sum + arr[e][i]));
    //     visit[i] = true;
    //     sw = false;
    //   }
    // }
  }
  return make_pair(ansIndex, ansSum);
}

int main() {
  cin >> n;
  arr.resize(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a].push_back(make_pair(b, c));
    arr[b].push_back(make_pair(a, c));
  }

  pair <int, int> end = dfs(1);
  cout << dfs(end.first).second;
}