// #include <iostream>

// using namespace std;

// long long dp[10'002], p, q;

// long long get_dp(int idx) {
//   if(dp[idx] != -1) return dp[idx];
//   return dp[idx] = (get_dp(idx - 1) + get_dp(idx - 2)) % 2'100'000'000;
// }

// int main() {
//   for(int i = 0; i < 10'002; i++) dp[i] = -1;
//   dp[0] = 0;
//   dp[1] = 1;
//   dp[2] = 1;

//   int t, cnt = 1; cin >> t;
//   while(t--) {
//     cin >> p >> q;
//     cout << "Case #" << cnt++ << ": " << get_dp(p) % q << '\n';
//   }
// }

#include <iostream>
#include <vector>

using namespace std;

long long get_fibo(int p, int q) {
  vector <long long> f(p+1);
  f[0] = 0;
  f[1] = f[2] = 1;

  for(int i = 3; i <= p; i++) {
    f[i] = f[i - 1] + f[i - 2];
    f[i] %= q;
  }

  return f[p] % q;
}

int main() {
  int t, p, q, cnt = 1; cin >> t;
  while(t--) {
    cin >> p >> q;
    cout << "Case #" << cnt++ << ": " << get_fibo(p, q) << '\n';
  }
}