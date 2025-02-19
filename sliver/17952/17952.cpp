#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int mt; cin >> mt;
  stack <pair <int, int>> s;

  int n, ans = 0;
  pair <int, int> t;
  while(mt--) {
    cin >> n;
    if(n != 0) {
      cin >> t.first >> t.second;
      s.push(t);
    }
    if(!s.empty()) {
      t = s.top(); s.pop();
      t.second--;
      if(t.second == 0) ans += t.first;
      else s.push(t);
    }
  }

  cout << ans;
}