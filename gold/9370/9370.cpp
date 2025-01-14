#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair <int, int>;

int n;
vector <vector <pii>> arr;
// pair <int, vector<int>> ans;

vector <int> dijkstra(int start) {
  vector <int> dist (n + 1, -1);
  priority_queue <pii, vector <pii>, greater <pii>> q;

  dist[start] = 0;
  q.push({0, start});

  while(!q.empty()) {
    int value = q.top().first, node = q.top().second;
    q.pop();
    if(dist[node] < value) continue;

    for(int i = 0; i < arr[node].size(); i++) {
      int new_node = arr[node][i].second, new_value = value + arr[node][i].first;
      if(dist[new_node] > new_value || dist[new_node] == -1) {
        dist[new_node] = new_value;
        q.push({new_value, new_node});
      }
    }
  }

  return dist;
}

void solve() {
  arr.clear();

  int s, g, h, m, t;
  vector <int> e, ans;
  cin >> n >> m >> t;
  cin >> s >> g >> h;
  arr.resize(n + 1);
  for(int i = 0; i < m; i++) {
    int a, b, d; cin >> a >> b >> d;
    arr[a].push_back({d, b});
    arr[b].push_back({d, a});
  }
  for(int i = 0; i < t; i++) {
    int a; cin >> a;
    e.push_back(a);
  }

  vector <int> 
  S = dijkstra(s),
  H = dijkstra(h),
  G = dijkstra(g);

  for(int i = 0; i < e.size(); i++) {
    int node = e[i];
    if(
      S[node] == S[g] + G[h] + H[node] ||
      S[node] == S[h] + H[g] + G[node]
    ) {
      ans.push_back(node);
    }
  }

  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  } cout << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}


// void set_ans(vector <vector <int>> dists) {
//   for(vector <int> dist: dists) {
//     cout << "step\n";
//     for(int i = 0; i < e.size(); i++) {
//       int value = dist[e[i]];
//       if(value > 0) {
//         if(value < ans.first) {
//           ans.first = value;
//           ans.second = vector <int> (1, e[i]);
//           cout << e[i] << ' ' << value << " hoooooooooooooooooooooooooooo!\n";
//         } else if(value == ans.first) {
//           ans.second.push_back(e[i]);
//           cout << e[i] << ' ' << value << " siuuuuuuuuuuuuuuuuuuuuuuuuuuu!\n";
//         }
//       }
//     }
//   }
// }

//==================main==================

// void disconnecting(int a, int b) {
//   for(int i = 0; i < arr[a].size(); i++) {
//     if(arr[a][i].second == b) {
//       arr.erase(arr.begin() + i);
//     }
//   }
// }


  // vector <int> normal_dist = dijkstra(s);

  // disconnecting(g, h);
  // disconnecting(h, g);

  // vector <int> disconnected_dist = dijkstra(s);

  // for(int i = 0; i < e.size(); i++) {
  //   int node = e[i];
  //   if(normal_dist[node] <= disconnected_dist[node] || disconnected_dist[node] == -1) {
  //     ans.push_back(node);
  //   }
  // }

  // sort(ans.begin(), ans.end());
  // for(int i = 0; i < ans.size(); i++) {
  //   cout << ans[i] << ' ';
  // } cout << '\n';
  
  // vector <vector <int>> set_ans_param;

  // ans.first = 2'100'000'000;

  // for(int i = 0; i < s_dist.size(); i++) cout << s_dist[i] << ' ';
  // cout << '\n';

  // if(s_dist[h] < s_dist[g]) {
  //   vector <int> temp = dijkstra(g);
  // for(int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
  // cout << '\n';
  //   set_ans_param.push_back(temp);
  // } else if(s_dist[h] > s_dist[g]) {
  //   vector <int> temp = dijkstra(h);
  // for(int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
  // cout << '\n';
  //   set_ans_param.push_back(temp);
  //   cout << 2 << '\n';
  // } else {
  //   set_ans_param.push_back(dijkstra(h));
  //   cout << 3 << '\n';
  //   set_ans_param.push_back(dijkstra(g));
  // }

  // set_ans(set_ans_param);

  // sort(ans.second.begin(), ans.second.end());
  // for(int i = 0; i < ans.second.size(); i++) {
  //   cout << ans.second[i] << ' ';
  // } cout << '\n';

