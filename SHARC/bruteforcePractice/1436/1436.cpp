#include <iostream>

using namespace std;

int ans = 2100000000;

bool hasSix(int e) {
  int cnt = 0;
  while(e) {
    int n = e % 10; e /= 10;
    if(n == 6) cnt++;
    else cnt = 0;
    if(cnt == 3) return true;
  }
  return false;
}

int main() {
  int n, i = 666; cin >> n;
  while(n--) {
    while(!hasSix(i)) {
      i++;
    }
    ans = i++;
  }

  cout << ans;
}