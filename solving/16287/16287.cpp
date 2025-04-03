#include <iostream>
#include <algorithm>

using namespace std;

int w, n, arr[5001];

int main() {
  cin >> w >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  for(int i = 0; i < n-3; i++) {
    for(int j = i + 1; j < n-2; j++) {
      int l = j + 1, r = n-1, t = w - arr[i] - arr[j], sum;
      while(l < r) {
        sum = arr[l] + arr[r];
        if(sum == t) {
          cout << "YES";
          return 0;
        }
        if(sum < t) {
          l++;
        } else {
          r--;
        }
      }
    }
  }

  cout << "NO";
}