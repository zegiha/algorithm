#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int
n,
p[100'001][18],
dist[100'001][18],
h[100'001],
mh,
e[100'001];
vector <vector <pair <int, int>>> arr;

void init_p() {
  int currnet_height = 1;
  queue <int> q;
  vector <bool> visit (n + 1);

  q.push(1);
  visit[1] = true;
  h[1] = currnet_height;

  while(!q.empty()) {
    currnet_height++;
    int size = q.size();
    while(size--) {
      int node = q.front();
      q.pop();
      for(int i = 0; i < arr[node].size(); i++) {
        if(!visit[arr[node][i].first]) {
          visit[arr[node][i].first] = true;
          q.push(arr[node][i].first);
          p[arr[node][i].first][0] = node;
          dist[arr[node][i].first][0] = arr[node][i].second;
          h[arr[node][i].first] = currnet_height;
        }
      }
    }
  }

  int tmp = n;
  while(tmp) {
    tmp = tmp >> 1;
    mh++;
  }

  for(int j = 1; j <= mh; j++) {
    for(int i = 1; i <= n; i++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
      dist[i][j] = dist[i][j - 1] + dist[p[i][j - 1]][j -1];
    }
  }
}

int get_ans(int node, int energy) {
  int res = node;
  for(int i = 0; i <= mh; i++) {
    if(dist[node][i] >= 0 && dist[node][i] <= energy) {
      res = p[node][i];
      // cout << i << ' ' << dist[node][i] << '\n';
    }
  }
  // cout << "============\n";
  if(res == 0) res = 1;
  return res;
}

int main() {
  // for(int i = 0; i < 100'001; i++) for(int j = 0; j < 18; j++) dist[i][j] = -1;

  cin >> n;

  for(int i = 0; i < n; i++) cin >> e[i];

  int a, b, c;
  arr.resize(n + 1, vector <pair <int, int>> (0));
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b >> c;
    arr[a].push_back({b, c});
    arr[b].push_back({a, c});
  }

  init_p();
  for(int i = 0; i < n; i++) {
    cout << get_ans(i + 1, e[i]) << '\n';
    // cout << "===========\n";
  }
}