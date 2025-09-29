#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector <vector <int>> arr;

bool vis[101];
int ocp[101] = {0, };

bool isOcp(int node) {
  if(vis[node]) return false;
  vis[node] = true;

  for(auto v : arr[node]) {
    if(ocp[v] == 0 || isOcp(ocp[v])) {
      ocp[v] = node;
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

  int a, b;

  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    arr[a].push_back({b});
  }

  for(int i = 1; i <= n; i++) {
    for(int i = 0; i < 101; i++) vis[i] = false;
    if(isOcp(i)) {
      ans++;
    }
  }

  cout << ans;
}