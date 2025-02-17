#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int s, e, ans;
bool check[2001][2001];

int get_gcd(int s, int b) {
  if(s == 0) {
    return b;
  }
  return get_gcd(b % s, s);
}

int main() {
  cin >> s >> e;

  for(int i = s; i <= e; i++) {
    for(int j = 1; j <= i; j++) {
      int gcd = get_gcd(j, i);
      if(!check[j / gcd][i / gcd]) {
        ans++;
        check[j / gcd][i / gcd] = true;
      }
    }
  }

  cout << ans;
}