#include <iostream>

using namespace std;

int n, multitapN, multitap[101], arr[101], ans;

struct State {
  int empty = -1;
  bool isPluged = false;
};

State getState(int index) {
  State req;
  int e = arr[index], minValue = 2100000000;
  for(int i = 0; i < multitapN; i++) {
    if(multitap[i] == e) req.isPluged = true;
    if(multitap[i] == 0 && req.empty == -1) req.empty = i;
  }

  return req;
}

int getDistance(int index) {
  pair <int, int> req = make_pair(-1, -1);
  for(int i = 0; i < multitapN; i++) {
    bool sw = true;
    for(int j = index; j < n; j++) {
      if(arr[j] == multitap[i]) {
        if(req.first < j - index) {
          req.first = j - index;
          req.second = i;
        }
        sw = false;
        break;
      }
    }
    if(sw) {
      req.first = 110;
      req.second = i;
    }
  }

  return req.second;
}

int main() {
  cin >> multitapN >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  for(int i = 0; i < n; i++) {
    // bool tmp = false;
    State state = getState(i);
    if(!state.isPluged) {
      if(state.empty != -1) {
        multitap[state.empty] =  arr[i];
      } else {
        // cout << i << ": " << multitap[getDistance(i)] << "  ||  " << arr[i] << endl;
        multitap[getDistance(i)] = arr[i];
        ans++;
        // tmp = true;
      }
    }
    // for(int i = 0; i < multitapN; i++) cout << multitap[i] << ' ';
    // if(tmp) cout << " + 1";
    // cout << endl;
  }

  cout << ans;
}

// 빈도수를 기준으로 뽑으면 
// 2 8
// 1 2 3 4 3 4 2 2
// 위와 같은 반례가 생김

// #include <iostream>
// #include <vector>

// using namespace std;

// int n, m, arr[100], multitap[100], sum[8], ans;

// struct State {
//   vector <int> empty;
//   bool isHere = false;
//   int min;
// };

// State getState(int index) {
//   State req;
//   int e = arr[index], minValue = 2100000000;
//   for(int i = 0; i < n; i++) {
//     if(multitap[i] == e) req.isHere = true;
//     if(multitap[i] == 0) req.empty.push_back(i);
//     if(sum[multitap[i]] < minValue) {
//       minValue = sum[multitap[i]];
//       req.min = i;
//     }
//   }

//   return req;
// }

// int main() {
//   int prev = 0;
//   cin >> n >> m;
//   for(int i = 0; i < m; i++) {
//     cin >> arr[i];
//     if(prev != arr[i]) {
//       sum[arr[i]]++;
//       prev = arr[i];
//     }
//   }

//       for(int i = 1; i < 8; i++) cout << sum[i] << ' ';
//     cout << endl;

//   for(int i = 0; i < m; i++) {
//     State state = getState(i);
//     if(!state.isHere) {
//       if(state.empty.size()) { // 멀티탭이 일부 비어있는 경우
//         multitap[state.empty[0]] = arr[i];
//       } else { // 어떤 코드를 빼야하는 경우 => 향후 사용 횟수가 제일 적은 코드를 빼면 됨
//         multitap[state.min] = arr[i];
//         ans++;
//       }
//     }
//     sum[arr[i]]--;
//     for(int i = 0; i < n; i++) cout << multitap[i] << ' '; cout << "  ||  ";
//     for(int i = 1; i < 8; i++) cout << sum[i] << ' ';
//     cout << endl;
//   }
  
//   cout << ans;
// }

// // #include <iostream>
// // #include <vector>

// // using namespace std;

// // int n, sum[7], ans;
// // vector <int> arr, multitap;

// // int isEmpty(int index) {
// //   for(int i = 0; i < n; i++) if(multitap[i] == -1) return i;
// //   return -1;
// // }
// // bool isHere(int e) {
// //   for(int i = 0; i < n; i++) {
// //     if(multitap[i] == e) return true;
// //   }
// //   return false;
// // }
// // int getRemove() {
// //   pair <int, int> min = {2100000000, -1};
// //   for(int i = 0; i < n; i++) {
// //     if(sum[multitap[i]] < min.first) min = {sum[multitap[i]], i};
// //   }
// //   return min.second;
// // }

// // int main() {
// //   int t;
// //   cin >> n >> t;
// //   multitap.resize(n, -1);
// //   while(t--) {
// //     int i; cin >> i; i--;
// //     sum[i]++;
// //     arr.push_back(i);
// //   }
// //   for(int i = 0; i < arr.size(); i++) {
// //     if(!isHere(arr[i])) {
// //       int empty = isEmpty(i);
// //       if(empty != -1) {
// //         multitap[empty] = arr[i];
// //         sum[arr[i]]--;
// //       } else {
// //         multitap[getRemove()] = arr[i];
// //         sum[arr[i]]--;
// //         ans++;
// //         cout << "Plused!!  ||  ";
// //       }
// //     } else sum[arr[i]]--;
// //     cout << endl;
// //     for(int i = 0; i < n; i++) cout << multitap[i] << ' ';
// //   }
// //   cout << ans;
// // }