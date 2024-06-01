#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int a, b, gcd = 0, lcm = 1000 * 1000;
    cin >> a >> b;
    for(int i = 1; i <= a * b; i++) {
      if((a % i == 0) && (b % i == 0)) gcd = i;
      if((i % a == 0) && (i % b == 0)) if(i < lcm) lcm = i;
    }
    cout << lcm << ' ' << gcd << '\n';
  }
}