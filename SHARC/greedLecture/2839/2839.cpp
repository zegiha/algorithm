#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
bool sw;
vector <int> arr;

int main() {
  cin >> n;
  arr.resize(n + 1);

  arr[n] = 1;
  while(!sw) {
    sw = true;
    for(int i = 1; i <= n; i++) {
      if(arr[i] == 1) {
        if(i >= 5 && !arr[i - 5]) arr[i - 5] = 1;
        if(i >= 3 && !arr[i - 3]) arr[i - 3] = 1;
        arr[i] = 2;
        sw = false;
      }
    }
    cnt++;
    if(arr[0] == 1) {
      cout << cnt;
      return 0;
    }
  }
  cout << -1;
}


// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// int n, cnt;
// vector <bool> dp;

// int main() {
//   cin >> n;
  
//   queue <int> q;
//   q.push(n);
//   while(!q.empty()) {
//     int size = q.size();
//     for(int t = 0; t < size; t++) {
//       int e = q.front();q.pop();
//       if(e == 0) {
//         cout << cnt;
//         return 0;
//       }
//       if(e >= 3) q.push(e - 3);
//       if(e >= 5) q.push(e - 5);
//     }
//     cnt++;
//   }
//   cout << -1;
// }