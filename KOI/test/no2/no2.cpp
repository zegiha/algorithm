#include <iostream>
#include <vector>

using namespace std;

void solve() {
  bool sw = true;
  int n, f, b; cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  f = arr[0]; b = arr[0];

  for(int i = 1; i < n; i++) {
    if(arr[i] - 1 == b || arr[i] + 1 == f) {
      if(arr[i] -1 == b) b = arr[i];
      else f = arr[i];
    } else {
      cout << "no\n";
      sw = false;
      break;
    }
  }

  if(sw) cout << "yes\n";
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}