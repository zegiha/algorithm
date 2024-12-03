#include <iostream>

using namespace std;

int arr[1'000'001], n;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0, l = 0, r = 1, s = 0, b = 0, cnt = 1;

  while(r < n) {
    int newItem = arr[r];
    if(l >= r) {
      cnt = 1;
      r++;
      s = l;
      b = l;
    } else if(newItem >= arr[s] && newItem <= arr[b]) {
      r++;
      cnt++;
    } else {
      if(newItem < arr[s]) {
        if(arr[b] - newItem > 2) {
          for(int i = l; i < r; i++) {
            if(arr[i] - newItem > 2) l = i + 1;
          }
          s = l; b = l;
          for(int i = l; i < r; i++) {
            if(arr[s] > arr[i]) s = i;
            if(arr[b] < arr[i]) b = i;
          }
          if(cnt > ans) ans = cnt;
          cnt = r - l;
        } else {
          s = r;
          cnt++;
          r++;
        }
      } else {
        if(newItem - arr[s] > 2) {
          for(int i = l; i < r; i++) {
            if(newItem - arr[i] > 2) l = i + 1;
          }
          s = l; b = l;
          for(int i = l; i < r; i++) {
            if(arr[s] > arr[i]) s = i;
            if(arr[b] < arr[i]) b = i;
          }
          if(cnt > ans) ans = cnt;
          cnt = r - l;
        } else {
          b = r;
          cnt++;
          r++;
        }
      }
    }
  }
  if(cnt > ans) ans = cnt;

  cout << ans;
}