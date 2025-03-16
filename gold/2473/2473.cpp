#include <iostream>
#include <algorithm>
#include <vector>

#define INF 4'200'000'000

using namespace std;
using ll = long long;

ll arr[5001], n;
pair <ll, vector <int>> ans = {INF, vector <int> (0)};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  for(int i = 0; i < n-2; i++) {
    int l = i+1, r = n-1;
    while(l < r) {
      ll v = arr[i] + arr[l] + arr[r];
      if(abs(v) < ans.first) {
        vector <int> t; t.push_back(i); t.push_back(l); t.push_back(r);
        ans = {abs(v), t};
      }
      if(v < 0) l++;
      else if(v > 0) r--;
      else break;
    }
  }

  for(int i = 0; i < 3; i++) cout << arr[ans.second[i]] << ' ';
}

// #include <iostream>
// #include <algorithm>
// #include <vector>

// #define INF 4'200'000'000

// using namespace std;
// using ll = long long;

// int n;
// ll arr[5001];
// pair <ll, vector <int>> ans = {INF, vector <int> (0)};

// int main() {
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> arr[i];
//     sort(arr, arr + n);

//     for(int i = 1; i < n-1; i++) {
//         int l = 0, r = n-1;
//         while(l < r) {
            
//         }
//     }
// }

// #include <iostream>
// #include <algorithm>
// #include <vector>

// #define INF 4'200'000'000

// using namespace std;
// using ll = long long;

// int n;
// ll arr[5001];
// pair <ll, vector <int>> ans = {INF, vector <int> (0)};

// int get_nearby(ll target) {
//     int l = 0, r = n-1, m;

//     while(l <= r) {
//         m = (l + r) / 2;
//         if(arr[m] < target) {
//             l = m+1;
//         } else {
//             r = m-1;
//         }
//     }

//     return l;
// }

// int main() {
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> arr[i];
//     sort(arr, arr + n);

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             if(i == j) continue;
//             int k = get_nearby((arr[i] + arr[j]) * -1);
//             if(ans.first > abs(arr[k] + arr[i] + arr[j])) {
//                 ans = {abs(arr[k] + arr[i] + arr[j]), vector <int> (0)};
//                 ans.second.push_back(i); ans.second.push_back(j); ans.second.push_back(k);
//             }
//         }
//     }

//     for(int i = 0; i < 3; i++) cout << ans.second[i] << ' ';
// }