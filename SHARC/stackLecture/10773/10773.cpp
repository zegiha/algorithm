#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack <int> s;
  int t, ans = 0; cin >> t;
  while(t--) {
    int n; cin >> n;
    if(n != 0) s.push(n);
    else s.pop();
  }
  while(!s.empty()) {
    ans += s.top();
    s.pop();
  }

  cout << ans;
}