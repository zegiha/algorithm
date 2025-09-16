#include <iostream>
#include <vector>
#include <map>

using namespace std;
using pii = pair <int, int>;

int Find(int t, vector <pii> &parent) {
  if(parent[t].first < 0) return t;
  return parent[t].first = Find(parent[t].first, parent);
}

void Union(int a, int b, vector <pii> &parent) {
  int aRoot = Find(a, parent), bRoot = Find(b, parent);

  if(aRoot != bRoot) {
    parent[aRoot].second += parent[bRoot].second;
    parent[bRoot].first = aRoot;
  }
}

void solve() {
  map <string, int> nameMap;
  vector <pii> parent;
  int n;

  cin >> n;

  int idx = 0;
  string a, b;
  bool isANew, isBNew;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;

    isANew = nameMap.find(a) == nameMap.end(), isBNew = nameMap.find(b) == nameMap.end();
    
    if(isANew) {
      nameMap.insert({a, idx++});
      parent.push_back({-1, 1});
    }
    if(isBNew) {
      nameMap.insert({b, idx++});
      parent.push_back({-1, 1});
    }

    Union(nameMap[a], nameMap[b], parent);
    int aRoot = Find(nameMap[a], parent);

    cout << parent[aRoot].second << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while(t--) {
    solve();
  }
}