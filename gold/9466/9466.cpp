#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector <int> arr;
vector <bool> visit, cycle;

void dfs(int node) {
  int nextNode = arr[node];
  visit[node] = true;
  if(!visit[nextNode]) {
    dfs(nextNode);
  }
  else if(!cycle[nextNode]) {
    // cout << node << endl;
    for(int i = nextNode; i != node; i = arr[i]) {
      ans++;
    }
    ans++;
    // cout << ans << endl;
  }
  cycle[node] = true;
}

void solve() {
  cin >> n;
  ans = 0;
  arr.resize(n + 1, 0);
  cycle.resize(n + 1, false);
  visit.resize(n + 1, false);
  for(int i = 1; i <= n; i++) cin >> arr[i];
  
  for(int i = 1; i <= n; i++) {
    if(!visit[i]) {
      dfs(i);
    }
  }
  cout << n - ans << endl;
  for(int i = 0; i <= n; i++) {
    arr[i] = 0;
    visit[i] = false;
    cycle[i] = false;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}

// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// int n, cnt;
// vector <int> arr;
// vector <bool> visit, done;

// void dfs(int node) {
//   int next = arr[node];
//   visit[node] = true;
//   if(!visit[next]) {
//     dfs(next);
//   }
//   if(!done[next]) {
//     for(int i = next; i != node; i = arr[i]) {
//       done[i] = true;
//       cnt++;
//     }
//     done[node] = true;
//     cnt++;
//   }
// }

// void solve() {
//   cin >> n;
//   arr.resize(n + 1, 0);
//   done.resize(n + 1, false);
//   visit.resize(n + 1, false);
//   cnt = 0;
//   for(int i = 1; i <= n; i++) cin >> arr[i];
//   for(int i = 1; i <= n; i++) {
//     if(!visit[i]) {
//       dfs(i);
//     }
//   }
//   cout << n - cnt << endl;
// }

// int main() {
//   int t;
//   cin >> t;
//   while(t--) solve();
// }

// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// int n, ans;
// vector <int> arr, endNode;
// vector <bool> mainVisit;

// void delNode(int e) {
//   // cout << "tlqkf" << endl;
//   if(mainVisit[e]) {
//     return;
//   }
//   // cout << e << endl;
//   mainVisit[e] = true;
//   for(int i = 1; i <= n; i++) {
//     if(!mainVisit[i] && arr[i] == e) delNode(i);
//   }
// }

// void dfs(int e, vector <bool> visit) {
//   // cout << "check\n";
//   // cout << mainVisit[e] << "  ||  " << arr[e] << endl;
//   if(mainVisit[e]) {
//     // cout << e << endl;
//     endNode.push_back(e);
//     return;
//   }

//   visit[e] = true;
//   mainVisit[e] = true;
//   dfs(arr[e], visit);
//   if(visit[endNode.back()]) {
//     ans--;
//   }
//   for(int i = 1; i <= n; i++) {
//     if(!mainVisit[i] && arr[i] == e) delNode(i);
//   }
// }

// void solve() {
//   cin >> n;
//   ans = n;
//   arr.resize(n + 2, 0);
//   mainVisit.resize(n + 2);
//   for(int i = 1; i <= n; i++) {
//     cin >> arr[i];
//   }
//   for(int i = 1; i <= n; i++) {
//     if(!mainVisit[i]) {
//       dfs(i, vector <bool> (n + 2));
//     }
//   }
//   cout << ans;
//   for(int i = 0; i <= n + 1; i++) {
//     arr[i] = 0;
//     mainVisit[i] = false;
//   }
// }

// int main() {
//   int t;
//   cin >> t;
//   while(t--) solve();
// }