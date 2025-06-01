#include <iostream>

using namespace std;

int arr[50], s, n;

void swap(int a, int b) {
  int t = arr[a];
  arr[a] = arr[b];
  arr[b] = t;
}

int moveMaxAndGetMovedNumber(int s, int e) {
  int maxIdx = s, res = 0;
  for(int i = s; i <= e; i++) {
    if(arr[maxIdx] < arr[i])
      maxIdx = i;
  }
  while(s < maxIdx--) {
    swap(maxIdx + 1, maxIdx);
    res++;
  }
  return res;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  cin >> s;

  for(int i = 0; i < n; i++) {
    s -= moveMaxAndGetMovedNumber(i, min(i + s, n-1));
    if(s <= 0) break;
  }

  for(int i = 0; i < n; i++) cout << arr[i] << ' ';

  return 0;
}