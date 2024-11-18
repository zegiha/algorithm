#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair <int, int>;

int n, d, v1, v2;
vector <vector <pii>> arr;

vector <int> ekdlrtmxmfldk(int s) {
  vector <int> dist (n + 1, -1);
  priority_queue <pii, vector <pii>, greater<pii>> q;

  dist[s] = 0;
  q.push({0, s});
  while(!q.empty()) {
    pii item = q.top(); q.pop();
    if(dist[item.second] != -1 && item.first > dist[item.second]) continue;

    int newDist, arrSecond;
    for(int i = 0; i < arr[item.second].size(); i++) {
      newDist = item.first + arr[item.second][i].first;
      arrSecond = arr[item.second][i].second;
      if(newDist < dist[arrSecond] || dist[arrSecond] == -1) {
        dist[arrSecond] = newDist;
        q.push({newDist, arrSecond});
      } 
    }
  }

  return dist;
}

int main() {
  cin >> n >> d;
  int a, b, w;
  arr.resize(n + 1);
  for(int i = 0; i < d; i++) {
    cin >> a >> b >> w;
    arr[a].push_back({w, b});
    arr[b].push_back({w, a});
  }
  cin >> v1 >> v2;

  vector <int> s = ekdlrtmxmfldk(1);
  vector <int> v = ekdlrtmxmfldk(v1);
  vector <int> e = ekdlrtmxmfldk(n);


  bool firstCaseSw = true, secondCaseSw = true;

  if(s[v1] == -1 || e[v2] == -1 || v[v2] == -1) firstCaseSw = false;
  if(s[v2] == -1 || e[v1] == -1 || v[v2] == -1) secondCaseSw = false;

  int firstCase = -1, secondCase = -1;
  if(firstCaseSw) firstCase = s[v1] + e[v2] + v[v2];
  if(secondCaseSw) secondCase = s[v2] + e[v1] + v[v2];

  cout << min(firstCase, secondCase);
}
