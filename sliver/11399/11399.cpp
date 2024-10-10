#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, arr[1001];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int ans = 0, t = 0;
  for(int i = 0; i < n; i++) {
    t += arr[i];
    ans += t;
  }

  cout << ans;
}