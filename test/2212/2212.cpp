#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10'001], n, k, ans;
vector <int> dist;

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  for(int i = 1; i < n; i++) dist.push_back(arr[i] - arr[i - 1]);
  sort(dist.begin(), dist.end(), cmp);

  for(int i = k - 1; i < dist.size(); i++) ans += dist[i];

  cout << ans;
}