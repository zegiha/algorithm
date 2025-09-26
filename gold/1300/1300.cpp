#include <iostream>

using namespace std;

int main() {
  int n, k; cin >> n >> k;
  int ans = k;

  int l = 1, r = k, m;
  while(l <= r) {
    m = (r + l) / 2;

    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += min(m / i, n);

    if(cnt >= k) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << ans;
}