#include <iostream>

using namespace std;

struct area {
  int start_r;
  int start_c;
  int end_r;
  int end_c;
};

bool isArea(area area, int r, int c) {
  return area.start_r <= r && r < area.end_r &&
  area.start_c <= c && c < area.end_c;
}

int pow(int n) {
  int res = 1;
  for(int i = 0; i < n; i++) res *= 2;
  return res;
}

int getAns(int r, int c, int n, int cnt) {
  int plus = pow(n - 1) * pow(n - 1), half_plus = pow(n - 1);

  if(n == 0) return cnt;

  // cout << n << " : " << cnt << '\n';

  area first = {0, 0, pow(n - 1), pow(n - 1)};
  if(isArea(first, r, c)) {
    return getAns(r, c, n - 1, cnt);
  }

  area second = {0, pow(n - 1), pow(n - 1), pow(n)};
  if(isArea(second, r, c)) {
    return getAns(r, c - half_plus, n - 1, cnt + plus);
  }

  area third = {pow(n - 1), 0, pow(n), pow(n - 1)};
  if(isArea(third, r, c)) {
    return getAns(r - half_plus, c, n - 1, cnt + plus * 2);
  }

  return getAns(r - half_plus, c - half_plus, n - 1, cnt + plus * 3);
}

int main() {
  int r, c, n;
  cin >> n >> r >> c;
  cout << getAns(r, c, n, 0);
}