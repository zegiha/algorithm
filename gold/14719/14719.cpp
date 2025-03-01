#include <iostream>

using namespace std;

int w, h, arr[501], ans;

int main() {
  cin >> h >> w;
  for(int i = 0; i < w; i++) cin >> arr[i];

  for(int current = 0; current <= h; current++) {
    int p = -1, cnt = 0;
    for(int i = 0; i < w; i++) {
      if(arr[i] >= current) {
        if(p == 0) {
          ans += cnt;
          cnt = 0;
        }
        p = 1;
      } else if(p != -1) {
        p = 0;
        cnt++;
      }

      // cout << current << ' ' << i << " -> p=" << p << " ans=" << ans << " cnt=" << cnt << '\n';
    }
    // cout << "===========\n";
  }

  cout << ans;
}