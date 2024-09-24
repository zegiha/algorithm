#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100001], ansI;
long long ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  long long newAns = 0;
  for(int i = 0; i < n; i++) {
    newAns = ((long long)arr[i]) * ((long long)(n - i));
    if(ans < newAns) {
      ans = newAns;
      ansI = arr[i];
    }
  }
  cout << ans << ' ' << ansI;
}