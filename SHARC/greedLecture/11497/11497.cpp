// #include <iostream>
// #include <algorithm>


// using namespace std;

// void solve() {
//   int n, arr[10000], ans[10000];
//   cin >> n;
//   for(int i = 0; i < n; i++) cin >> arr[i];
//   sort(arr, arr + n);
//   for(int i = 0; i < n; i++) cout << arr[i] << ' ';
//   for(int i = 0; i < n / 2; i++) {
//     ans[i] = arr[i];
//     ans[n - i - 1] = arr[i + 1];
//   }
// }

// int main() {
//   int t; cin >> t;
//   while(t--) {solve();}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getGap(int a, int b) {
  if(a > b) return a - b;
  return b - a;
}

int main() {
  int t; cin >> t;
  while(t--) {
    int n, ans;
    vector <int> arr, ansArr;
    cin >> n;
    arr.resize(n);
    ansArr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());


    // 배열을 작은 순으로 1 3 5 7 6 4 2 이런 순으로 바꿔주는 작업
    for(int i = 0, arrIndex = 0; i < n / 2; i++, arrIndex += 2) {
      ansArr[i] = arr[arrIndex];
      ansArr[n - 1 - i] = arr[arrIndex + 1];
    }
    if(n % 2 != 0) ansArr[n / 2] = arr[n - 1];
    
    // for(int i = 0; i < n; i++) cout << ansArr[i] << ' ';
    // cout << endl;

    ans = getGap(ansArr[0], ansArr[n - 1]);
    for(int i = 0; i < n - 1; i++) {
      int gap = getGap(ansArr[i], ansArr[i + 1]);
      if(gap > ans) ans = gap;
    }
    cout << ans << endl;
  }
}