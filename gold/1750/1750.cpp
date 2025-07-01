#include <iostream>
#include <algorithm>

#define MOD 10000003

using namespace std;
using ll = long long;

ll n, arr[50], dp[50][100'001];

ll getGcd(ll a, ll b) {
  if(a % b == 0) return b;
  return getGcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  sort(arr, arr + n);
  for(int i = 0; i < n; i++) {
    dp[i][arr[i]] = 1;
    
    if(i == 0) continue;
    for(int j = 1; j <= arr[i]; j++) dp[i][j] += dp[i-1][j];
    for(int j = 1; j <= arr[i]; j++) {
      ll gcd = getGcd(arr[i], j);
      dp[i][gcd] = (dp[i][gcd] + dp[i-1][j]) % MOD;
    }
  }

  cout << dp[n-1][1];
}