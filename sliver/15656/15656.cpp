#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> arr;

vector <int> record;
void backtrack(int depth) {
  if(depth == m) {
    for(int i = 0; i < m; i++) cout << arr[record[i]] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 0; i < n; i++) {
    record.push_back(i);
    backtrack(depth + 1);
    record.pop_back();
  }
}

int main() {
  cin >> n >> m;
  arr.resize(n); for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());

  backtrack(0);
}