#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

ll n, arr[500'001], ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  stack <ll> s;
  for(int i = 0; i < n; i++) {
    if(s.empty()) {
      s.push(arr[i]);
    } else {
      while(!s.empty() && s.top() < arr[i]) {
        s.pop();
        ans++;
      }
      s.push(arr[i]);
      ans += s.size() - 1;
    }
  }

  cout << ans;
}