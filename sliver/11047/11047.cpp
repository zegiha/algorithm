#include <iostream>

using namespace std;

int n, m, arr[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int ans = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(arr[i] > m) continue;
    ans += m / arr[i];
    m = m % arr[i];
  }

  cout << ans;
  return 0;
}