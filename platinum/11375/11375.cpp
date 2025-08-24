#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> arr;

int occupy[1001];
bool visited[1001];
bool solve(int i) {
  for(int j = 0; j < arr[i].size(); j++) {
    int p = arr[i][j];
    if(visited[p]) continue;
    visited[p] = true;

    if(occupy[p] == 0 || solve(occupy[p])) {
      occupy[p] = i;
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
  arr.resize(n + 1, {});
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
    for(int i = 0; i < 1001; i++) visited[i] = false;
    if(solve(i)) {
      ans++;
    }
  }

  cout << ans;
}