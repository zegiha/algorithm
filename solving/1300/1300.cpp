#include <iostream>

using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  cout << (ll)((k % n + 1) * (k / n + 1));
}