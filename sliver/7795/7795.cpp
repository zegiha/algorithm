#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[20'001], b[20'001], ans;

void input() {
  ans = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];
}

pair <int, int> get_idx(int std) {
  int l = 0, r = m - 1, mid;
  while(l <= r) {
    mid = (l + r) / 2;

    if(b[mid] < std) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return {l, r};
}

void solve() {
  sort(a, a + n);
  sort(b, b + m);

  pair <int, int> idx;
  for(int i = 0; i < n; i++) {
    idx = get_idx(a[i]);

    ans += max(0, idx.first);
    // cout << "---------------" << idx.first << ' ' << idx.second << ' ' << i << '\n';
  }
  
  // cout << "==============";
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    input();
    solve();
  }
}