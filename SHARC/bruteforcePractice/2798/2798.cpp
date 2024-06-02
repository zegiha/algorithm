#include <iostream>

using namespace std;

int n, m, arr[101], ans;

void solve(int index, int sum, int cnt) {
  if(cnt == 3) {
    if(sum <= m && ans < sum) ans = sum;
    return;
  }
  for(int i = index; i < n; i++) {
    solve(i + 1, sum + arr[i], cnt + 1);
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  for(int i = 0; i < n; i++) {
    solve(i + 1, arr[i], 1);
  }

  cout << ans;
}