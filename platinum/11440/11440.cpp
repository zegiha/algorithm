#include <iostream>
#include <map>

#define MOD 1000000007

using namespace std;
using ll = long long;

map <ll, ll> memo;

ll fibo(ll n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  if(n == 2) return 1;
  if(memo[n] != 0) return memo[n];

  if(n % 2 == 0) {
    ll fiboN = fibo(n/2), fiboNM = fibo(n/2 - 1), fiboNP = fibo(n/2 + 1);
    return memo[n] = (((fiboN * fiboNM) % MOD) + ((fiboN * fiboNP) % MOD)) % MOD;
  }
  else {
    ll a = n / 2 + 1, b = n / 2;
    ll fiboA = fibo(a), fiboAM = fibo(a-1), fiboB = fibo(b), fiboBP = fibo(b + 1);
    return memo[n] = (((fiboAM * fiboB) % MOD) + ((fiboA * fiboBP) % MOD)) % MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n; cin >> n;

  cout << (fibo(n) * fibo(n + 1)) % MOD;
}