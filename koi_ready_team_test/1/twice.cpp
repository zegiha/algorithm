#include <iostream>

using namespace std;

void solve() {
  int n, arr[21] = {0,};
  cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    arr[tmp]++;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += arr[i] / 2;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}