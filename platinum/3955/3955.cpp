#include <iostream>

using namespace std;
using ll = long long;

ll mod(ll a, ll b) {
  return ((a % b) + b) % b;
}

ll gcd(ll a, ll b) {
  if(!b) return a;
  else return gcd(b, a % b);
}

ll extGcd(ll a, ll b, ll &x, ll &y) {
  ll g = a; x = 1, y = 0;
  if(b) return extGcd(b, a % b, y, x), y -= a / b * x;
  return g;
}

ll inv(ll a, ll m) {
  ll x, y;
  ll g = extGcd(a, m, x,y);
  return mod(x, m);
}

void solve() {
  ll c, k;
  cin >> k >> c;

  if(k == 1 && c == 1) {
    cout << 2 << '\n';
    return;
  }
  if(c == 1) {
    if(k + 1 > 1e9) cout << "IMPOSSIBLE\n";
    else cout << k + 1 << '\n';
    return;
  }
  if(k == 1) {
    cout << 1 << '\n';
    return;
  }
  if(gcd(k, c) != 1) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  ll t = inv(c, k);
  if(t > 1e9) {
    cout << "IMPOSSIBLE\n";
    return;
  } else {
    cout << t << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int t; cin >> t;
  while(t--) solve();
}