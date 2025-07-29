#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

ll n, l, w, h;

int getMax(int a, int b, int c) {
  ll bigger = max(a, b);
  return bigger > c ? bigger : c;
}

int main() {
  cin >> n >> l >> w >> h;

  ll canBePut;
  double left = 0.0, right, mid;
  right = 1'000'000'000.0;
  for(int i = 0; i < 10000; i++) {
    mid = (right + left) / 2.0;
    canBePut = ((ll)(l / mid)) * ((ll)(w / mid)) * ((ll)(h / mid));
    if(n <= canBePut) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << fixed;
  cout.precision(10);
  cout << left;
}