#include <iostream>
#define int long long

using namespace std;

signed main() {
  int n; cin >> n;
  int one = 1, zero = 0, ans = 1;

  // one: 길이가 i이고, 맨 끝 자리 수가 1인 수의 개수
  // zero: 길이가 i이고, 맨 끝 자리 수가 0인 수의 개수

  for(int i = 2; i <= n; i++) {

    int new_one = zero;
    int new_zero = one + zero;

    one = new_one;
    zero = new_zero;
  }

  cout << one + zero;
  return 0;
}