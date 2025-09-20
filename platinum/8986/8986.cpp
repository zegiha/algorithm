#include <iostream>

using namespace std;
using ll = long long;

ll n, arr[100'001];

ll getCost(int d) {
  ll cnt = 0;
  for(int i = 1; i < n; i++) {
    cnt += abs(1LL * d * i - arr[i]);
  }

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  ll lo = 0, hi = arr[n-1], p, q;
  while(hi - lo >= 3) {
    p = (lo * 2 + hi) / 3, q = (lo + hi * 2) / 3;
    if(getCost(p) <= getCost(q)) hi = q;
    else lo = p;
  }

  ll ans = getCost(hi);
  for(int i = lo; i < hi; i++) ans = min(getCost(i), ans);

  cout << ans;
}
