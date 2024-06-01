#include <iostream>
#include <vector>
using namespace std;

int arr[9];
bool sw = false;

void solve(int index, int sum, int cnt, vector <int> ans) {
  if(cnt == 7) {
    if(sum == 100) {
      sw = true;
      for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    }
    return;
  }
  for(int i = index; i < 9; i++) {
    if(sum + arr[i] <= 100 && !sw) {
      ans.push_back(arr[i]);
      solve(i + 1, sum + arr[i], cnt + 1, ans);
      ans.pop_back();
    }
  }
}

int main() {
  for(int i = 0; i < 9; i++) cin >> arr[i];
  for(int i = 0; i < 3; i++) {
    vector <int> ans; ans.push_back(arr[i]);
    solve(i + 1, arr[i], 1, ans);
  }
}