#include <iostream>

using namespace std;

const long long INF = 1'000'000'000;

long long ans = 1;
int n, m, a[1001], b[1001];

long long get_gcd(long long high, long long low) {
  return high % low ? get_gcd(low, high % low) : low;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for(int i = 0; i < m; i++) cin >> b[i];

  bool is_bigger = false;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      long long gcd;
      if(a[i] < b[j]) gcd = get_gcd(b[j], a[i]);
      else gcd = get_gcd(a[i], b[j]);

      ans *= gcd;
      if(ans >= INF) {
        ans %= INF;
        is_bigger = true;
      }

      a[i] /= gcd;
      b[j] /= gcd;
    }
  }

  if(is_bigger) {
    printf("%09lld", ans);
  } else {
    cout << ans;
  }
}