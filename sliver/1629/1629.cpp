#include <iostream>

#define INF 2147483647

using namespace std;
using ll = long long;

ll a, b, c, ans;

ll solve(ll n) {
  if(n == 0) return 1;
  if(n == 1) return a%c;

  if(n % 2 == 0) return solve(n/2) * solve(n/2) % c;
  else return ((solve(n/2) * solve(n/2) % c) * a) % c;
}

int main() {
  cin >> a >> b >> c;
  
  cout << solve(b);
}