#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, arr[1001];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  while(m--) {
    long long newCard = arr[0] + arr[1];
    arr[0] = newCard;
    arr[1] = newCard;
    sort(arr, arr+n);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    ans += arr[i];
  }

  cout << ans;
}