#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
vector <int> arr, ans;

int main() {
  cin >> n; arr.resize(n); ans.resize(n, -1);
  for(int i = 0; i < n; i++) cin >> arr[i];

  stack <pair <int, int>> s;
  s.push({arr[0], 0});
  for(int i = 1; i < n; i++) {
    while(!s.empty() && s.top().first < arr[i]) {
      ans[s.top().second] = arr[i];
      s.pop();
    }
    s.push({arr[i], i});
  }

  for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}