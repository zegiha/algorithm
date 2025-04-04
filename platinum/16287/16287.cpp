#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int targetWeight, n, arr[5001], dp1[400'001], dp2[400'001];

int main() {
  cin >> targetWeight >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));

  for(int i = 0; i < n-1; i++) {
    for(int j = i + 1; j < n; j++) {
      int w = arr[i] + arr[j];
      if(dp1[w] == -1) {
        dp1[w] = i;
        dp2[w] = j;
      }
    }
  }

  for(int i = 0; i < n-1; i++) {
    for(int j = i + 1; j < n; j++) {
      int w = targetWeight - (arr[i] + arr[j]);
      if(w > 400'000 || w < 0 || dp1[w] < 0) continue;
      if(dp1[w] != i && dp2[w] != j && dp1[w] != j && dp2[w] != i) {
        cout << "YES";
        return 0;
      }
    }
  }

  cout << "NO";
}