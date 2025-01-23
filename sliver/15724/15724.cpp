#include <iostream>

using namespace std;

int n, m, arr[1025][1025];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
      arr[i][j] += sum;
      sum = arr[i][j];
    }
  }

  int k, sr, sc, er, ec;
  cin >> k;
  while(k--) {
    cin >> sr >> sc >> er >> ec;
    sr--; sc--; er--; ec--;
    
    int ans = 0;
    for(int i = sr; i <= er; i++) {
      if(sc != 0) {
        ans += arr[i][ec] - arr[i][sc - 1];
      } else {
        ans += arr[i][ec];
      }
    }
    cout << ans << '\n';
  }
}