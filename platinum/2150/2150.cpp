#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, id;
vector <int> parent;
vector <bool> finished;
vector <vector <int>> arr, scc;
stack <int> s;

int dfs(int idx) {
  parent[idx] = ++id;
  s.push(idx);

  int child, p = parent[idx];
  for(int i = 0; i < arr[idx].size(); i++) {
    child = arr[idx][i];
    if(parent[child] == -1) p = min(p, dfs(child));
    else if(!finished[child]) p = min(p, parent[child]);
  }

  if(p == parent[idx]) {
    int tmp;
    vector <int> newScc;
    while(1) {
      tmp = s.top();
      s.pop();
      finished[tmp] = true;
      newScc.push_back(tmp);
      if(idx == tmp) break;
    }
    scc.push_back(newScc);
  }

  return p;
}

bool cmp(vector <int> a, vector <int> b) {
  return a[0] < b[0];
}

int main() {
  cin >> n >> m;

  parent.resize(n + 1, -1);
  finished.resize(n + 1, false);
  arr.resize(n + 1, vector <int> (0));

  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    arr[a].push_back(b);
  }

  for(int i = 1; i <= n; i++) {
    if(parent[i] == -1) dfs(i);
  }

  cout << scc.size() << '\n';
  for(int i = 0; i < scc.size(); i++) sort(scc[i].begin(), scc[i].end());
  sort(scc.begin(), scc.end(), cmp);
  for(int i = 0; i < scc.size(); i++) {
    for(int j = 0; j < scc[i].size(); j++) cout << scc[i][j] << ' ';
    cout << "-1\n";
  }
}