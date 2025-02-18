#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> arr;

int binarySearch(int s, int e, int targetIndex) {
  while(s <= e) {
    int m = (e - s) / 2 + s;
    // cout << s << ' ' << m <<  ' ' << e << '\n';
    if(arr[m] * arr[targetIndex] == n-2) {
      return arr[m];
    }
    if(arr[m] * arr[targetIndex] > n - 2) {
      e = m - 1;
    } else if(arr[m] * arr[targetIndex] < n - 2) {
      s = m + 1;
    }
  }
  return -1;
}

void solve() {
  cin >> n;
  arr.resize(n);
  for(int i = 0 ; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  for(int i = 0; i < n; i++) {
    int res = binarySearch(i + 1, n - 1, i);
    // cout << "==========================\n";
    if(res != -1) {
      cout << res << ' ' << arr[i] << '\n';
      return;
    }
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}