#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans, a;
vector <pair <int, int>> arr;

bool compare(pair <int, int> a, pair <int, int> b) {
  if(a.second == b.second) {
    return a.second - a.first > b.second - b.first;
  }
  return a.second < b.second;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    arr.push_back(make_pair(a, b));
  }

  sort(arr.begin(), arr.end(), compare);
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i].first >= a) {
      a = arr[i].second;
      ans++;
    }
  }
  cout << ans;
}