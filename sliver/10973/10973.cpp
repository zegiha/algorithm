#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, arr[10'001];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int end_of_desc = n - 1;
  while(end_of_desc >= 1) {
    if(arr[end_of_desc] < arr[end_of_desc - 1]) {
      break;
    }
    end_of_desc--;
  }
  if(end_of_desc == 0) {
    cout << -1;
    return 0;
  }
  for(int i = n - 1; i >= end_of_desc; i--) {
    if(arr[i] < arr[end_of_desc - 1]) {
      int t = arr[i];
      arr[i] = arr[end_of_desc - 1];
      arr[end_of_desc - 1] = t;
      break;
    }
  }
  sort(arr+end_of_desc, arr+n, greater<>());

  for(int i = 0 ; i < n; i++) {
    cout << arr[i] << ' ';
  }
}