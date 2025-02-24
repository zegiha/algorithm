#include <iostream>

using namespace std;

#define MAX_PRIME 5'000'001

int n, prime[MAX_PRIME];

void set_prime() {
  for(int i = 2; i < MAX_PRIME; i++) {
    if(prime[i] == 0) {
      for(int j = i; j < MAX_PRIME; j += i) {
        if(prime[j] == 0) prime[j] = i;
      }
    }
  }
}

void solve() {
  cin >> n;
  while(n > 1) {
    cout << prime[n] << ' ';
    n /= prime[n];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  set_prime();

  int t; cin >> t;
  while(t--) solve();
}