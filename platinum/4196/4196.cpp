#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int
n,
m,
id,
sccCnt,
indegree[100'001],
sccId[100'001],
dis[100'001];
vector <vector <int>> arr;
stack <int> s;

int SCC(int idx) {
  int ret = dis[idx] = id++;
  s.push(idx);

  for(auto& next : arr[idx]) {
    if(dis[next] == -1) {
      ret = min(ret, SCC(next));
    } else if(sccId[next] == -1) {
      ret = min(ret, dis[next]);
    }
  }

  if(ret == dis[idx]) {
    int t;

    while(true) {
      t = s.top();
      s.pop();

      sccId[t] = sccCnt;
      if(t == idx) break;
    }

    sccCnt++;
  }

  return ret;
}

void init() {
  arr.clear();
  sccCnt = 0;
  id = 0;
  for(int i = 0; i < 100'001; i++) {
    sccId[i] = -1;
    dis[i] = -1;
    indegree[i] = 0;
  }

  while(!s.empty()) s.pop();
}

void solution() {
  init();

  cin >> n >> m;

  arr.resize(n + 1, {});

  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    arr[a].push_back(b);
  }

  for(int i = 1; i <= n; i++) {
    if(dis[i] == -1) {
      SCC(i);
    }
  }

  for(int i = 1; i <= n; i++) {
    for(auto& next : arr[i]) {
      if(sccId[i] == sccId[next]) continue;
      indegree[sccId[next]]++;
    }
  }

  int ans = 0;
  for(int i = 0; i < sccCnt; i++) {
    if(indegree[i] == 0) ans++;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while(t--) {
    solution();
  }
}