#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> arr;

bool visited[1011], fixedNode[1011];
int occupy[1011];
bool isOccupyAndOccupy(int node) {
  // cout << "node: " << node << '\n';

  if(visited[node]) return false;
  visited[node] = true;

  for(int i = 0; i < arr[node].size(); i++) {
    int t = arr[node][i];

    // cout << "child: " << t << '\n';

    if(occupy[t] == 0 || isOccupyAndOccupy(occupy[t])) {
      occupy[t] = node;
      return true;
    }
  }

  return false;
}

void solve() {
  arr.clear();
  for(int i = 0; i < 1001; i++) occupy[i] = 0;

  int n, m, a, b, ans = 0;
  cin >> n >> m;

  arr.resize(m + 2, {});
  for(int i = 1; i <= m; i++) {
    cin >> a >> b;
    for(int j = a; j <= b; j++) {
      arr[i].push_back(j);
    }
  }

  // for(int i = 1; i <= m; i++) {
  //   cout << i << ": ";
  //   for(auto v : arr[i]) cout << v << ' ';
  //   cout << '\n';
  // }

  for(int i = 1; i <= m; i++) {
    for(int i = 0; i < 1001; i++) visited[i] = false;
    // cout << "============================\n";
    if(isOccupyAndOccupy(i)) ans++;
    // cout << "============================\n";
    // for(int i = 1; i <= n; i++) cout << occupy[i] << ' '; cout << '\n';
  }



  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while(t--) {
    solve();
  }
}
