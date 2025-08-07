#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, k;

int main() {
  ll ans = 0;
  cin >> n >> k;

  // int cnt = 0;
  // for(int i = 1; i <= k; i++) {
  //   if(i == k) {
  //     ans += (n - i + 1) * i;
  //     // cout << "(" << n << " - " << i << " + 1" << ")" << " * " << i << " = " << (n - i + 1) * i << '\n';
  //   }
  //   else {
  //     ans += (n - i) * i;
  //     // cout << "(" << n << " - " << i << ")" << " * " << i << " = " << (n - i) * i << '\n';
  //   }
  // }

  ll ans2 = 0;
  for(int i = 1; i <= k; i++) {
    ans2 += (ll)(n - i) * (ll)i;
  }
  ans2 += k;

  // cout << ans << ' ' << ans2;

  cout << ans2;
}
