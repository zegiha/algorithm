#include <iostream>
using namespace std;

int arr[1002], ans;

int main() {
  int cnt = 1, cnt2 = 0;
  for(int i = 1; i <= 1000; i++) {
    arr[i] = cnt;
    cnt2++;
    if(cnt == cnt2) {
      cnt++;
      cnt2 = 0;
    }
  }

  int a, b; cin >> a >> b;
  for(int i = a; i <= b; i++) {
    ans += arr[i];
  }

  cout << ans;
}