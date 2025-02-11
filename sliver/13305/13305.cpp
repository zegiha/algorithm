#include <iostream>

using namespace std;

int n, dist[100'000], value[100'001];

int main() {
  cin >> n;
  for(int i = 0; i < n - 1; i++) cin >> dist[i];
  for(int i = 0; i < n; i++) cin >> value[i];

  int small = 2'100'000'000;
  long long ans = 0, cnt = 0;

  for(int i = 0; i < n - 1; i++) {
    if(small > value[i]) {
      ans += small * cnt;
      cnt = 0;
      small = value[i];
    }

    cnt += dist[i];
  }

  if(cnt > 0) {
    ans += small * cnt;
  }

  cout << ans;

  return 0;
}