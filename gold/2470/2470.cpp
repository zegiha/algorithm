#include <iostream>
#include <algorithm>

using namespace std;

struct ANS {
  int value;
  int i;
  int ii;
};
struct DISTENCE {
  int distence;
  int index;
};


int n, arr[100'000];

DISTENCE getUpperDistence(int pivot, int pivotIndex) {
  int l = 0, r = n - 1, m, distence = 2'100'000'000;
  DISTENCE ans = {2'100'000'000, -1};

  while(l <= r) {
    m = (l + r) / 2;
    distence = abs(pivot - arr[m]);

    if(pivot <= arr[m]) {
      r = m - 1;
    } else {
      l = m + 1;
    }

    if(distence < ans.distence && m != pivotIndex) {
      ans = {distence, m};
    }
  }

  return ans;
}

DISTENCE getLowerDistence(int pivot, int pivotIndex) {
  int l = 0, r = n - 1, m, distence = 2'100'000'000;
  DISTENCE ans = {2'100'000'000, -1};

  while(l <= r) {
    m = (l + r) / 2;
    distence = abs(pivot - arr[m]);

    if(pivot >= arr[m]) {
      l = m + 1;
      
    } else {
      r = m - 1;
    }

    if(distence < ans.distence && m != pivotIndex) {
      ans = {distence, m};
    }
  }

  return ans;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  ANS ans = {2'100'000'000, -1, -1}, newAns = {2'100'000'000, -1, -1};
  for(int i = 0; i < n; i++) {
    DISTENCE lowerDistence = getLowerDistence(arr[i] * -1, i);
    DISTENCE upperDistence = getUpperDistence(arr[i] * -1, i);

    // cout << lowerDistence.index <<  ' ' << upperDistence.index << '\n';
    if(lowerDistence.index == -1 && lowerDistence.index == upperDistence.index) continue;

    if(lowerDistence.distence > upperDistence.distence) {
      newAns = {abs(arr[i] + arr[upperDistence.index]), upperDistence.index, i};
    } else {
      newAns = {abs(arr[i] + arr[lowerDistence.index]), lowerDistence.index, i};
    }

    if(ans.value > newAns.value) ans = newAns;
  }

  if(ans.i > ans.ii) {
    int t = ans.i;
    ans.i = ans.ii;
    ans.ii = t;
  }

  cout << arr[ans.i] << ' ' << arr[ans.ii];
}