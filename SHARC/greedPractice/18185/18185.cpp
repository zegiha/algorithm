#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector <int> arr;

void delThree(int i) {
  for(int j = 0; j < 3; j++) if(arr[i + j] <= 0) return;
  int diff = arr[i] > arr[i + 1] ? arr[i + 1] : arr[i];
  if(diff > arr[i + 2]) diff = arr[i + 2];

  for(int j = 0; j < 3; j++) arr[i + j] -= diff;
  ans += 7 * diff;
}
void delTwo(int i) {
  for(int j = 0; j < 2; j++) if(arr[i + j] <= 0) return;
  int diff = arr[i] > arr[i + 1] ? arr[i + 1] : arr[i];
  
  for(int j = 0; j < 2; j++) arr[i + j] -= diff;
  ans += 5 * diff;
}
void delOne(int i) {
  if(arr[i] <= 0) return;
  ans += 3 * arr[i];
  arr[i] = 0;
}

int main() {
  cin >> n; arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  for(int i = 0; i < n; i++) {
    if(arr[i]) {
      if(arr[i + 1] > arr[i + 2] && i + 2 < n && i + 1 < n) {
        int diff = arr[i] > arr[i + 1] - arr[i + 2] ? arr[i + 1] - arr[i + 2] : arr[i];
        arr[i] -= diff;
        arr[i + 1] -= diff;
        ans += 5 * diff;
        delThree(i);  
        delOne(i);
      } else {
        delThree(i);
        delTwo(i);
        delOne(i);
      }
    }
    // for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    // cout << "  ||  " << ans << '\n';
  }

  cout << ans;
}
