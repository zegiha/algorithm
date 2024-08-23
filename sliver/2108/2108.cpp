#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, arr[500001];

int getSameValueIndex(vector <pair <int, int>>* same, int compare) {
  for(int i = 0; i < same->size(); i++) {
    if((*same)[i].first == compare) return i;
  }
  return -1;
}

bool compare(pair <int, int> a, pair <int, int> b) {
  if(a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

int rounding(double req) {
  return (int)floor(req + 0.5);
}

int getModerate(vector <pair <int, int>>* same) {
  int key = 0;
  if(same->size() > key + 1) if((*same)[key].second == (*same)[key + 1].second) key++;
  
  return (*same)[key].first;
}

int main() {
  int sum=0, max=-2100000000, min=2100000000;
  vector <pair <int, int>> same;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];

    sum += arr[i];

    if(arr[i] > max) max = arr[i];
    if(arr[i] < min) min = arr[i];
    
    int sameValueIndex = getSameValueIndex(&same, arr[i]);
    if(sameValueIndex == -1) {
      same.push_back({arr[i], 1});
    } else {
      same[sameValueIndex].second++;
    }
  }

  sort(arr, arr + n);
  sort(same.begin(), same.end(), compare);

  // for(int i = 0; i < same.size(); i++) cout << same[i].first << ' ' << same[i].second << '\n';

  int
  ans1 = rounding((double)sum / (double)n),
  ans2 = arr[n / 2],
  ans3 = getModerate(&same),
  ans4 = max - min;

  // cout << max << ' ' << min << '\n';

  cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n' << ans4;

}