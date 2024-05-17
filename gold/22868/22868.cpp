#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans;
vector <vector <int>> arr;
vector <int> backRoad;

int bfs(int start, int end) {
  int cnt = 1;
  queue <int> q;
  vector <bool> check;
  check.resize(n + 1, false);
  q.push(start);
  check[start] = true;
  if(backRoad[start] != -1) {
    // cout << "tlqkf?\n";
    int t = backRoad[start];
    while(t != -1) {
      // cout << t << endl;
      check[t] = true;
      t = backRoad[t];
    }
  }
  check[end] = false;
  // for(int i = 1; i <= n; i++) cout << check[i] << " ";
  // cout << endl << "*********************\n";

  // cout << "start: " << start << endl;
  // cout << "backRoad[end]: " << backRoad[end] << endl;
  while(!q.empty()) {
    int size = q.size();
    for(int t = 0; t < size; t++) {
      int e = q.front();
      q.pop();
      for(int i = 0; i < arr[e].size(); i++) {
        if(!check[arr[e][i]]) {
          check[arr[e][i]] = true;
          q.push(arr[e][i]);
          backRoad[arr[e][i]] = e;
          if(arr[e][i] == end) return cnt;
        }
      }
    }
    cnt++;
  }
}

int main() {
  int s, e;
  cin >> n >> m;
  arr.resize(n + 1);
  backRoad.resize(n + 1, -1);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  cin >> s >> e;
  for(int i = 1; i <= n; i++) {
    sort(arr[i].begin(), arr[i].end());
  }

  ans += bfs(s, e);
  ans += bfs(e, s);
  cout << ans;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;

// int n, m, S, E, ans;
// vector <vector <int>> arr;
// vector <bool> visit;

// void bfs() {
//   int cnt = 1;
//   bool sw = false;
//   queue <int> q;
//   q.push(S);
//   visit[S] = true;
//   // cout << "tlqkf\n";
//   while(!q.empty()) {
//     int size = q.size();
//     // cout << e << endl;
//     for(int t = 0; t < size; t++) {
//       int e = q.front();
//       q.pop();
//       for(int i = 0;  i < arr[e].size(); i++) {
//         if(!visit[arr[e][i]]) {
//           if(arr[e][i] == E) {
//             ans += cnt;
//             if(!sw) sw = true;
//             else return;
//           } else {
//             visit[arr[e][i]] = true;
//             q.push(arr[e][i]);
//           }
//         }
//       }
//     }
//     cnt++;
//   }
// }

// int main() {
//   cin >> n >> m;
//   arr.resize(n + 1);
//   visit.resize(n + 1, false);
//   for(int i = 0; i < m; i++) {
//     int a, b;
//     cin >> a >> b;
//     arr[a].push_back(b);
//     arr[b].push_back(a);
//   }
//   cin >> S >> E;
//   for(int i = 1; i <= n; i++) {
//     sort(arr[i].begin(), arr[i].end());
//   }

//   // for(int i = 1; i <= n; i++) {
//   //   cout << i << ": ";
//   //   for(int j = 0; j < arr[i].size(); j++) {
//   //     cout << arr[i][j] << ' ';
//   //   }
//   //   cout << endl;
//   // }

//   bfs();
//   cout << ans;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int n, m, S, E, ans;
// vector <vector <int>> arr;
// vector <bool> visit;

// int main() {
//   cin >> n >> m;
//   arr.resize(n + 1);
//   visit.resize(n + 1, false);
//   for(int i = 0; i < m; i++) {
//     int a, b;
//     cin >> a >> b;
//     arr[a].push_back(b);
//     arr[b].push_back(a);
//   }
//   cin >> S >> E;
  
//   int cnt = 0;
//   queue <int> q;
//   q.push(S);
//   visit[S] = true;
//   while (!q.empty()) {
//     cnt++;
//     int size = q.size();
//     for(int i = 0; i < size; i++) {
//       int e = q.front();
//       q.pop();
//       for(int i = 0; i < arr[e].size(); i++) {
//         if(!visit[arr[e][i]]) {
//           if(arr[e][i] == E) ans += cnt;
//           q.push(arr[e][i]);
//           visit[arr[e][i]] = true;
//         } else if(arr[e][i] == E) {
//           ans += cnt;
//           break;
//         }
//       }
//     }
//   }
//   cout << ans;
// }