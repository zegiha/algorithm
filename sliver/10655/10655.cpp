#include <iostream>
#include <cmath>

using namespace std;

int arr[100'001][2], n, dp[100'001], sum;

int get_dist(int a, int b) {
  return abs(arr[a][0] - arr[b][0]) + abs(arr[a][1] - arr[b][1]);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
    if(i != 0) {
      sum += get_dist(i-1, i);
    }
  }

  int max_reduction = 2'100'000'000;
  for(int i = 1; i < n-1; i++) {
    int
      viaduct = get_dist(i-1, i) + get_dist(i, i+1),
      transfer = get_dist(i-1, i+1);
    max_reduction = max_reduction > transfer-viaduct ?
      transfer-viaduct:
      max_reduction;
  }

  cout << sum + max_reduction;
}