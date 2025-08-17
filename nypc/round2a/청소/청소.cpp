#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
  int n, l, ans = 0;
  cin >> n >> l;
  map <int, int> rm, cm;

  int r, c;
  while(n--) {
    cin >> r >> c;
    for(int i = r - 1; i <= r + l; i++) {
      rm[i] += 1;
      if(ans < rm[i]) ans = rm[i];
    }
    for(int i = c - l; i <= c + l; i++) {
      cm[i] += 1;
      if(ans < cm[i]) ans = cm[i];
    }
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