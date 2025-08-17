#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int n, k, arr[300'001], dif[300'001];
// ull ans = (ull)2'000'000'001 * (ull)300'000;
ull ans = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for(int i = 1; i < n; i++) {
    dif[i-1] = arr[i] - arr[i-1];
  }

  sort(dif, dif + (n-1));

  int cnt = 1;
  for(int i = 0; i < k-1; i++) {
    ans += (ull) dif[i] * cnt;
    if(dif[i] != 0) cnt++;
    // cout << dif[i] << '\n';
  }

  cout << ans;
}