#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int arr[3];
  while(cin >> arr[0] >> arr[1] >> arr[2]) {
    sort(arr, arr + 3);
    int ans = arr[2] - arr[1] > arr[1] - arr[0] ? arr[2] - arr[1] : arr[1] - arr[0];
    cout << ans - 1 << '\n';
  }
}