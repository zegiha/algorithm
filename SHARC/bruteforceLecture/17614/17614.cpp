#include <iostream>

using namespace std;

int main() {
  int e, ans = 0; cin >> e;
  for(int i = 1; i <= e; i++) {
    int n = i;
    while(n) {
      int tmp = n % 10; n /= 10;
      if(tmp % 3 == 0 && tmp != 0) ans++;
    }
  }
  cout << ans;
}