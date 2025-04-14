#include <iostream>
#include <map>

using namespace std;
using ll = long long;

map <int, ll> m;

int main() {
  int t; cin >> t;
  while(t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1) {
      auto t = m.begin();
      while(b) {
        ll tmp = t->second;
        while(tmp-- && b) b--;
        if(b) t++;
      }
      cout << "=============";
      cout << t->first << '\n';
      t->second--;
      if(t->second <= 0) m.erase(t->first);
    } else {
      cin >> c;
      if(m.find(b) != m.end()) {
        m[b] += c;
        if(m[b] <= 0) m.erase(b);
      } else {
        m.insert({b, c});
      }
    }
  }
}