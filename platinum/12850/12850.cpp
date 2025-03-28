#include <iostream>
#include <vector>

#define mod_v 1000000007

using namespace std;
using ll = long long;
using vvll = vector <vector <ll>>;

ll d;
vvll arr = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 0, 1},
  {0, 0, 0, 1, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 0, 1, 0}
};

vvll multiplying(vvll& a, vvll& b) {
  vvll res(8, vector <ll> (8, 0L));
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      for(int k = 0; k < 8; k++) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= mod_v;
      }
    }
  }
  return res;
}

vvll divide_and_conquer(vvll& v, ll n) {
  vvll nv;
  if(n == 1) return v;
  if(n % 2 != 0) {
    nv = divide_and_conquer(v, n-1);
    return multiplying(nv, v);
  } else {
    nv = divide_and_conquer(v, n / 2);
    return multiplying(nv, nv);
  }
}

int main() {
  cin >> d;
  vvll ans = divide_and_conquer(arr, d);
  cout << ans[0][0];
}