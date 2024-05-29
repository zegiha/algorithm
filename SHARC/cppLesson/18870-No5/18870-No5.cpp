#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <pair <pair <int, int>, int>> arr;

bool second(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
  return a.first.second < b.first.second;
}
bool first(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
  return a.first.first < b.first.first;
}

int main() {
  cin >> n;
  arr.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first.second;
    arr[i].first.first = i;
  }
  sort(arr.begin(), arr.end(), second);
  int prev = arr[0].first.second, cnt = 0;
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i].first.second != prev) {
      cnt++;
      prev = arr[i].first.second;
    }
    arr[i].second = cnt;
  }
  sort(arr.begin(), arr.end(), first);
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i].second << ' ';
  }
}