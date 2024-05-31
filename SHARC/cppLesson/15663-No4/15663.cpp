#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, arr[8];

bool isNew(int e, vector <int>* visit) {
  for(int i = 0; i < visit->size(); i++) {
    if((*visit)[i] == e) return false;
  }
  return true;
}

void solve(int cnt, vector <int> ans, vector <bool> usedI) {
  if(cnt == m) {
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  vector <int> v;
  for(int i = 0; i < n; i++) {
    if(isNew(arr[i], &v) && !usedI[i]) {
      v.push_back(arr[i]);
      ans.push_back(arr[i]);
      usedI[i] = true;
      solve(cnt + 1, ans, usedI);
      ans.pop_back();
      usedI[i] = false;
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  solve(0, vector <int> (0), vector <bool> (8));
}