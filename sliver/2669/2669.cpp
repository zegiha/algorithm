#include <iostream>

using namespace std;

int ans = 0;
bool arr[101][101] = {0, };

int main() {
  int t = 4, r, l, d, u;
  while(t--) {
    cin >> l >> d >> r >> u;

    for(int i = d; i < u; i++) {
      for(int j = l; j < r; j++) {
        arr[i][j] = true;
        cout << i << ", " << j << '\n';
      }
    }
    cout << "=======================\n";
  }

  for(int i = 1; i <= 100; i++) {
    for(int j = 1; j <= 100; j++) {
      if(arr[i][j]) ans++;
    }
  }

  cout << ans << "\n============================\n\n";

  for(int i = 8; i >= 0; i--) {
    for(int j = 8; j >= 0; j--) {
      if(arr[i][j]) cout << '1';
      else cout << '0';
    }
    cout << endl;
  }
}