#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, arr[200'000];
ll ans;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n*2; i++) cin >> arr[i];
  sort(arr, arr + n*2);
  for(int i = 0; i < n*2; i += 2) {
    int playTime = min(arr[i], arr[i + 1]);
    // ll tmp = (arr[i] + arr[i + 1] - abs(arr[i] - arr[i + 1])) * (playTime / m);
    // cout << tmp << '\n';
    ans += (ll)(arr[i] + arr[i + 1] - abs(arr[i] - arr[i + 1])) * (ll)(playTime / m);

  }

  cout << ans;
}