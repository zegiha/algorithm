#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100001], ans;

bool compare(int a, int b) {return a > b;}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, compare);
  for(int i = 0; i < n; i += 3) {
    for(int j = i; j < i + 2; j++) {
      if(j >= n) break;
      ans += arr[j];
    }
  }

  cout << ans;
}