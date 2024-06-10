#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <bool> check;

int main() {
  int e = 2, cnt = 0;
  cin >> n >> k;
  check.resize(n + 1, false);
  check[1] = true;
  while(true) {
    if(!check[e]) {
      int t = 1;
      while(t * e <= n) {
          if(!check[t * e]) {
          check[t * e] = true;
          cnt++;
          if(cnt == k) {
            cout << t * e;
            return 0;
          }
        }
        t++;
      }
    } else e++;
  }
}