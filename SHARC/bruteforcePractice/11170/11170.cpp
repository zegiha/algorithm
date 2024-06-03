#include <iostream>

using namespace std;

int getZeroN(int start, int end) {
  int ans = 0;
  for(int i = start; i <= end; i++) {
    int tmp = i;
    if(i == 0) ans++;
    while(tmp) {
      if(!(tmp % 10)) ans++;
      tmp /= 10;
    }
  }
  return ans;
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    cout << getZeroN(n, m) << '\n';
  }
}