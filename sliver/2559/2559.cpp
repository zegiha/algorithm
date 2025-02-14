#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector <int> arr;

int main() {
  cin >> n >> k; arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  int ans = 0, new_ans;
  for(int i = 0; i < k; i++) {
    ans += arr[i];
  }
  
  new_ans = ans;
  for(int i = k; i < n; i++) {
    new_ans -= arr[i - k]; new_ans += arr[i];
    ans = max(new_ans, ans);
  }

  cout << ans;
}