#include <iostream>
#include <vector>

using namespace std;

int n, m, occupy[1001];
vector <vector <int>> arr;

bool visited[1001];
bool solve(int node) {
  for(auto& v : arr[node]) {
    if(visited[v]) continue;

    visited[v] = true;

    if(occupy[v] == 0 || solve(occupy[v])) {
      occupy[v] = node;
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  arr.resize(n + 2, {});

  int t, tt;
  for(int i = 1; i <= n; i++) {
    cin >> t;
    while(t--) {
      cin >> tt;
      arr[i].push_back(tt);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    t = 2;
    while(t--) {
      for(int i = 0; i < 1001; i++) visited[i] = false;
      if(solve(i)) ans++;
    }
  }

  cout << ans << '\n';
}