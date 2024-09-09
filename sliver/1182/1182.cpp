#include <iostream>
#include <vector>

using namespace std;

int n, s, arr[21], ans;

vector<int> record;

int getSum() {
  int sum = 0;
  for(int i = 0; i < record.size(); i++) {
    sum += arr[record[i]];
  }
  return sum;
}

void backtrack(int depth, int last, int endDepth) {
  if(depth == endDepth) {
    if(getSum() == s) {
      ans++;
    }
      // for(int i = 0; i < record.size(); i++) {
      //   cout << record[i] << ' ';
      // }
      // cout << '\n';
    return;
  }
  for(int i = last + 1; i < n; i++) {
    record.push_back(i);
    backtrack(depth + 1, i, endDepth);
    record.pop_back();
  }
}

int main() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  for(int i = 0; i < n; i++) {
    for(int d = 1; d <= n - i; d++) {
      record.push_back(i);
      backtrack(1, i, d);
      record.pop_back();
      // cout << "\n\n";
    }
  };

  cout << ans;
}