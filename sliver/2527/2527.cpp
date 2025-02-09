#include <iostream>

using namespace std;

void solve() {
  int x, y, p, q, x2, y2, p2, q2;
  cin >> x >> y >> p >> q >> x2 >> y2 >> p2 >> q2;

  if(p < x2 || q < y2 || x > p2 || y > q2) {
    cout << "d\n";
  } else {
    if(
      (p == x2 && q == y2) ||
      (x == p2 && q == y2) ||
      (x == p2 && y == q2) ||
      (p == x2 && y == q2)
    ) {
      cout << "c\n";
    } else {
      if(
        p == x2 ||
        q == y2 ||
        x == p2 ||
        y == q2
      ) {
        cout << "b\n";
      } else {
        cout << "a\n";
      }
    }
  }
}

int main() {
  int t = 4;
  while(t--) {
    solve();
  }
}