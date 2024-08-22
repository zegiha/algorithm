#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <bool> getPrime(int end) {
  int endSqrt = (int)sqrt(end);
  vector <bool> prime (end + 1, true);
  prime[0] = false;
  prime[1] = false;
  for(int i = 2; i <= endSqrt + 1; i++) {
    if(prime[i]) {
      int m = 2;
      while(i * m <= end) {
        prime[i * m] = false;
        m++;
      }
    }
  }

  return prime;
}

int main() {
  int s, e; cin >> s >> e;
  vector <bool> ans = getPrime(e);
  for(int i = s; i < ans.size(); i++) {
    if(i > e) break;
    if(ans[i]) cout << i << '\n';
  }
}