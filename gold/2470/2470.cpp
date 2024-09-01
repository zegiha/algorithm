#include <iostream>
#include <algorithm>

using namespace std;

struct ANS {
  int v;
  int f;
  int s;
};

int n, arr[100000];

int getSmallNearest(int pivot) {
  // bool sw = pivot == -999999996 ? true : false;
  int l = 0, r = n-1, m, ans = -2'100'000'000;
  
  while(l <= r) {
    m = (l + r) / 2;

    if(arr[m] > pivot) {
      // if(sw) cout << "haha1\n";
      r= m -1;
    } else if(arr[m] < pivot){
      // if(sw) cout << "ha2\n";
      ans = max(ans, arr[m]);
      l = m +1;
    } else return arr[m];

    if(l == r) ans = arr[m];
  }

  return ans;
}

int getBigNearest(int pivot) {
  int l = 0, r = n - 1, m, ans = 2'100'000'000;
  
  while(l <= r) {
    m = (l + r) / 2;

    if(arr[m] > pivot) {
      r = m-1;
      ans = min(ans, arr[m]);
    } else if(arr[m] < pivot){
      l = m+1;
    } else return arr[m];

    if(l == r) ans = arr[m];
  }

  return ans;
}

int getAbs(int req) {
  if(req < 0) return req * -1;
  return req;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  ANS ans = {2'100'000'000, -1, -1};
  for(int i = 0; i < n; i++) {
    int
    smallNearest = getSmallNearest(arr[i] * -1),
    bigNearest = getBigNearest(arr[i] * -1);
    
    if(smallNearest == arr[i] || smallNearest == -2'100'000'000) {
      if(i - 1 > -1) {smallNearest = arr[i - 1];}
    }
    if(bigNearest == arr[i] || bigNearest == 2'100'000'000) {
      if(i + 1 < n) {bigNearest = arr[i + 1];}
    }

    ANS newAns = {2'100'000'000, -1, -1};
    if(bigNearest == smallNearest && smallNearest == 2'100'000'000) continue;
    
    if(getAbs(arr[i] + smallNearest) > getAbs(arr[i] + bigNearest)) {
      newAns = {getAbs(arr[i] + bigNearest), arr[i], bigNearest};
    } else {
      newAns = {getAbs(arr[i] + smallNearest), arr[i], smallNearest};
    }

    if(ans.v > newAns.v) {
      if(newAns.f > newAns.s) {
        int t = newAns.f;
        newAns.f = newAns.s;
        newAns.s = t;
      }

      ans = newAns;
    }
  }

  cout << ans.f << ' ' << ans.s;
}
/*
5
1 1 1 1 1

3
-10 1 2

*/