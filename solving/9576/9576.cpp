#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> arr;

bool occupy[1011], visited[1011];
bool isOccupyAndOccupy(int node) {
  if(visited[node]) return false;
  visited[node] = true;

  for(int i = 0; i < arr[node].size(); i++) {
    int t = arr[node][i];

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

  for(int i = 1; i <= m; i++) {
    for(int i = 0; i < 1001; i++) visited[i] = false;
    if(isOccupyAndOccupy(i)) ans++;
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
