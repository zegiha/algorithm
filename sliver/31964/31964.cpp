#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> x, t;

void init() {
  cin >> n;
  x.resize(n); t.resize(n);
  for(int i = 0; i < n; i++) cin >> x[i];
  for(int i = 0; i < n; i++) cin >> t[i];
}

int solve() {
  int ans = 0;

  for(int i = 0 ; i < n; i++) {
    ans = max(ans, t[i] + (-2 * x[n - 1]) + x[i]);
  }

  return 2 * x[n - 1] + ans;
}

int main () {
  init();
  cout << solve();
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Pack {
//   int t; //time
//   int loc; //location
//   int minT; //minTime
//   int dist; // distance
// };

// int n, ans;
// vector <Pack> arr;

// bool compare (Pack a, Pack b) {
//   if(a.minT == b.minT) {
//     return a.loc > b.loc;
//   }
//   return a.minT < b.minT;
// }

// int getDist(int a, int b) {
//   if(a > b) return a - b;
//   return b - a;
// }

// int getMinT(int a, int b) {
//   if(a > b) return a;
//   return b;
// }

// int main () {
//   cin >> n; arr.resize(n);
//   for(int i = 0 ; i < n; i++) cin >> arr[i].loc;
//   for(int i = 0 ; i < n; i++) {
//     cin >> arr[i].t;

//     arr[i].dist = getDist(arr[i].loc, 0);
//     arr[i].minT = getMinT(arr[i].dist, arr[i].t);
//   }
//   sort(arr.begin(), arr.end(), compare);

//   while(arr.size()) {
//     Pack goal = arr[0];
//     arr.erase(arr.begin());

//     for(int i = 0; i < arr.size(); i++) {
//       arr[i].t -= goal.minT;
//       arr[i].dist = getDist(arr[i].loc, goal.loc);
//       arr[i].minT = getMinT(arr[i].dist, arr[i].t);
//     }
//     sort(arr.begin(), arr.end(), compare);
    
//     ans += goal.minT;
//     if(arr.size() == 0) {
//       ans += goal.loc;
//     }
//   }

//   cout << ans;
// }