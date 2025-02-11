#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pll = pair <long long, long long>;

struct cmp {
  bool operator()(pll a, pll b) {
    if(a.first == b.first) {
      return a.second > b.second;
    } else {
      return a.first > b.first;
    }
  }
};

long long abs_custom(long long a) {
  if(a > 0) return a;
  return a * -1;
}

int main() {
  priority_queue <pll, vector <pll>, cmp> q;
  long long t, n; cin >> t;
  while(t--) {
    cin >> n;
    if(n != 0) {
      q.push({abs_custom(n), n});
    } else {
      if(!q.empty()) {
        cout << q.top().second << '\n';
        q.pop();
      } else {
        cout << 0 << '\n';
      }
    }
  }
}
