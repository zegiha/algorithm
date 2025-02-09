#include <iostream>

using namespace std;

long long ans, n;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    ans += i * (n / i);
  }

  cout << ans;
}

// #include <iostream>

// using namespace std;

// long long n, dp[1'000'001], ans;

// long long get_dp(int idx) {
//   if(dp[idx] != -1) {
//     return dp[idx];
//   }

//   long long new_dp = 1 + idx;
//   for(int i = 2; i <= idx / 2; i++) {
//     if(idx % i == 0) {
//       new_dp += ;
//     }
//   }

//   dp[idx] = new_dp;
//   return dp[idx];
// }

// int main() {
//   cin >> n; for(int i = 0; i <= n; i++) dp[i] = -1;
//   for(int i = n; i >= 1; i--) {
//     ans += get_dp(i);
//   }
// }