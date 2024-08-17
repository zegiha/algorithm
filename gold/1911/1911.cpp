#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector <pair <int, int>> arr;

bool compare(pair <int, int> a, pair <int, int> b) {
  return a.second < b.second;
}

int main() {
  cin >> n >> l;
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    arr.push_back({a > b ? b : a, a > b ? a : b});
  }
  sort(arr.begin(), arr.end(), compare);

  int plank = 0, plankCnt = 0;
  for(int i = 0; i < n; i++) {
    if(arr[i].first > plank) {
      plank = arr[i].first;
    }

    while(plank < arr[i].second) {
      plank += l;
      plankCnt++;
    }
  }

  cout << plankCnt;
}