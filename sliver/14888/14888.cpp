#include <iostream>

using namespace std;

int n, arr[101], op[4], min_ans = 2'100'000'000, max_ans = -2'100'000'000;

int calc(int a, int b, int op) {
  switch (op) {
    case 0:
      return a + b;
    case 1:
      return a - b;
    case 2:
      return a * b;
    case 3:
      if(a < 0 && b > 0) {
        a *= -1;
        a /= b;
        return a * -1;
      } else return a / b;
  }
}

void set_ans(int idx, int cnt) {
  if(idx == n) {
    if(cnt < min_ans) min_ans = cnt;
    if(cnt > max_ans) max_ans = cnt;
  }

  for(int i = 0; i < 4; i++) {
    if(op[i] - 1 >= 0) {
      op[i]--;
      set_ans(idx + 1, calc(cnt, arr[idx], i));
      op[i]++;
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < 4; i++) cin >> op[i];

  set_ans(1, arr[0]);
  cout << max_ans << '\n' << min_ans;
}