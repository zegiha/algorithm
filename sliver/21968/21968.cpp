#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

vector <int> getBinary(long long n) {
  vector <int> res;
  while(n) {
    res.push_back(n % 2);
    n /= 2;
  }
  return res;
}

void solve() {
  long long n; cin >> n;
  vector<int> binary = getBinary(n);
  long long ans = 0;
  for(int i = 0; i < binary.size(); i++) {
    if(binary[i]) {
      long long plus = 1;
      for(int j = 0; j < i; j++) {
        plus *= 3;
      }
      ans += plus;
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}