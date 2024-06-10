#include <iostream>

using namespace std;

int x, y, gcd;

void getGcd(int a, int b) {
  if(a % b == 0) {
    gcd = b;
    return;
  }
  getGcd(b, a % b);
}

int main() {
  cin >> x >> y;
  if(x > y) {
    int tmp = x;
    x = y;
    y = tmp;
  }

  getGcd(x, y);
  cout << gcd << '\n' << x * y / gcd;
}