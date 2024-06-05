#include <iostream>
#include <vector>

using namespace std;

int n, m, arr[100], multitap[100], sum[8], ans;

struct State {
  vector <int> empty;
  bool isHere = false;
  int min;
};

State getState(int index) {
  State req;
  int e = arr[index], minValue = 2100000000;
  for(int i = 0; i < n; i++) {
    if(multitap[i] == e) req.isHere = true;
    if(multitap[i] == 0) req.empty.push_back(i);
    if(sum[multitap[i]] < minValue) {
      minValue = sum[multitap[i]];
      req.min = i;
    }
  }

  return req;
}

int main() {
  int prev = 0;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> arr[i];
    if(prev != arr[i]) {
      sum[arr[i]]++;
      prev = arr[i];
    }
  }

      for(int i = 1; i < 8; i++) cout << sum[i] << ' ';
    cout << endl;

  for(int i = 0; i < m; i++) {
    State state = getState(i);
    if(!state.isHere) {
      if(state.empty.size()) { // 멀티탭이 일부 비어있는 경우
        multitap[state.empty[0]] = arr[i];
      } else { // 어떤 코드를 빼야하는 경우 => 향후 사용 횟수가 제일 적은 코드를 빼면 됨
        multitap[state.min] = arr[i];
        ans++;
      }
    }
    sum[arr[i]]--;
    for(int i = 0; i < n; i++) cout << multitap[i] << ' '; cout << "  ||  ";
    for(int i = 1; i < 8; i++) cout << sum[i] << ' ';
    cout << endl;
  }
  
  cout << ans;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int n, sum[7], ans;
// vector <int> arr, multitap;

// int isEmpty(int index) {
//   for(int i = 0; i < n; i++) if(multitap[i] == -1) return i;
//   return -1;
// }
// bool isHere(int e) {
//   for(int i = 0; i < n; i++) {
//     if(multitap[i] == e) return true;
//   }
//   return false;
// }
// int getRemove() {
//   pair <int, int> min = {2100000000, -1};
//   for(int i = 0; i < n; i++) {
//     if(sum[multitap[i]] < min.first) min = {sum[multitap[i]], i};
//   }
//   return min.second;
// }

// int main() {
//   int t;
//   cin >> n >> t;
//   multitap.resize(n, -1);
//   while(t--) {
//     int i; cin >> i; i--;
//     sum[i]++;
//     arr.push_back(i);
//   }
//   for(int i = 0; i < arr.size(); i++) {
//     if(!isHere(arr[i])) {
//       int empty = isEmpty(i);
//       if(empty != -1) {
//         multitap[empty] = arr[i];
//         sum[arr[i]]--;
//       } else {
//         multitap[getRemove()] = arr[i];
//         sum[arr[i]]--;
//         ans++;
//         cout << "Plused!!  ||  ";
//       }
//     } else sum[arr[i]]--;
//     cout << endl;
//     for(int i = 0; i < n; i++) cout << multitap[i] << ' ';
//   }
//   cout << ans;
// }