#include <iostream>

using namespace std;

int n, k, dp[1001][1001];
const int mod = 1000000003;

int main() {
  cin >> n >> k;
  for(int i = 0; i <= n; i++) {
    dp[i][0] = 1;
    dp[i][1] = i;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 2; j <= k; j++) {
      dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
    }
  }

  int ans = (dp[n - 1][k] + dp[n - 3][k - 1]) % mod;
  cout << ans;
  return 0;
}

// #include <iostream>

// using namespace std;

// int n, k;

// int getRecurrenceRelation() {
//   return n - 1 - (2 * (k - 1));
// }

// int main() {
//   cin >> n >> k;

//   if(k == 1) {
//     cout << n;
//     return 0;
//   }
  
//   int ans = getRecurrenceRelation();
//   if(ans <= 0) {
//     cout << 0;
//     return 0;
//   }

//   int i = 0, ansCpy = ans;
//   long long tmp = ansCpy * ( 2 + (ansCpy - 1)) / 2;

//   ans += tmp % 1'000'000'003;

//   cout << ans;
//   return 0;
// }