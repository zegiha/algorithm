#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
vector <pair <int, int>> arr;

int main() {
  cin >> n;
  arr.resize(n + 1);
  for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
  sort(arr.begin(), arr.end());

  priority_queue <int, vector <int>, greater <int>> q;
  q.push(arr[0].second);
  for(int i = 1; i < n; i++) {
    if(arr[i].first >= q.top()) q.pop();
    q.push(arr[i].second);
  }

  cout << q.size();
}

// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// int n, ans;

// struct cmp {
//     bool operator()(pair <int, int> a, pair <int, int> b) {
//       if(a.first == b.first) a.second > b.second;
//         return a.first > b.first;
//     }
// };

// int main() {
//   priority_queue <pair <int, int>, vector <pair <int, int>>, cmp> q;
//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     int a, b; cin >> a >> b;
//     q.push(make_pair(a, b));
//   }

//   while(!q.empty()) {
//     priority_queue <pair <int, int>, vector <pair <int, int>>, cmp> nextQ;
//     int prevS = q.top().first, prevE = q.top().second;
//     q.pop();
//     while(!q.empty()) {
//       int nextS = q.top().first, nextE = q.top().second;
//       q.pop();
//       if(prevE > nextS) nextQ.push(make_pair(nextS, nextE));
//       else {
//         prevS = nextS;
//         prevE = nextE;
//       }
//     }
//     ans++;
//     q = nextQ;
//   }

//   cout << ans;
// }