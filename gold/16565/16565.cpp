#include <iostream>

#define MOD 10007

using namespace std;

int comb[53][53], n, ans;

int main() {
  for(int i = 0; i < 53; i++) comb[i][0] = 1;
  for(int i = 1; i < 53; i++) {
    for(int j = 1; j < 53; j++) {
      comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
    }
  }

  cin >> n;

  for(int i = 1; i <= 13 && n-4*i >= 0; i++) {
    if(i % 2) ans = (ans + comb[52-4*i][n-4*i] * comb[13][i]) % MOD;
    else ans = (ans - (comb[52-4*i][n-4*i] * comb[13][i]) % MOD + MOD) % MOD;
  }

  cout << ans << '\n';
}