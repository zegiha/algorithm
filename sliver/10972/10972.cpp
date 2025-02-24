#include <iostream>
#include <algorithm>

using namespace std;

int arr[10'001], n;;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int i = n - 1;
  while(i > 0 && arr[i - 1] > arr[i]) {
    i--;
  }
  if(i <= 0) {
    cout << -1;
    return 0;
  }

  i--;
  for(int j = n-1; j >= 0; j--) {
    if(arr[j] > arr[i]) {
      int t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      // cout << arr[i] << ' ' << arr[j] << '\n';
      break;
    }
  }

  sort(arr + i + 1, arr + n);
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}