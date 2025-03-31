#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

int n;
ll ans;

int main() {
  cin >> n;

  int now, height;
  stack <pair <int, int>> s;
  for(int i = 0; i < n; i++) {
    cin >> now; height = 1;
    while(!s.empty() && s.top().first < now) {
      ans += s.top().second;
      s.pop();
    }
    if(!s.empty()) {
      if(s.top().first == now) {
        ans += s.top().second;
        height = s.top().second + 1;
        if(s.size() > 1) ans++;
        s.pop();
      } else {
        ans++;
      }
    }
    s.push({now, height});
  }

  cout << ans;
}