#include <iostream>
#include <algorithm>

using namespace std;

int n, l, arr[51];

int abs(int req) {
  if(req < 0) return req * -1;
  return req;
}

int main() {
  cin >> l;
  for(int i = 0; i < l; i++) cin >> arr[i];
  cin >> n;
  sort(arr, arr + l);

  int betweenIndex = 0;
  while(arr[betweenIndex] < n) {
    betweenIndex++;
  }
  int s = arr[betweenIndex - 1], b = arr[betweenIndex];

  int ans = abs(s - n + 1) * (b - n) + (b - n - 1);
  if(ans >= 0) cout << ans;
  else cout << 0;
}