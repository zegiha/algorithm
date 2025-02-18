#include <iostream>

using namespace std;

int arr[501][501], n, m, total;

int get_niens(int n) {
  int res = 0;
  while(n > 0) {
    if(n % 10 == 9) res++;
    n /= 10;
  }
  return res;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int t; cin >> t;
      arr[i][j] = get_niens(t);
      total += arr[i][j];
    }
  }

  int max_break = 0;
  for(int i = 0; i < n; i++) {
    int cnt = 0;
    for(int j = 0; j < m; j++) {
      cnt += arr[i][j];
    }
    if(cnt > max_break) max_break = cnt;
  }
  for(int j = 0; j < m; j++) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      cnt += arr[i][j];
    }
    if(cnt > max_break) max_break = cnt;
  }

  cout << total - max_break;
}