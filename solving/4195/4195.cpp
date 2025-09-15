#include <iostream>
#include <vector>
#include <map>

using namespace std;
using pii = pair <int, int>;

int getRoot(int node, vector <pii> &parent) {
  if(parent[node].first == -1) {
    return node;
  } else return getRoot(parent[node].first, parent);
}

bool visited[200'002];
void liftingChildren(int node, int root, vector <pii> &parent, vector <vector <int>> &children) {
  for(int i = 0; i < children[node].size(); i++) {
    if(visited[children[node][i]]) continue;

    parent[children[node][i]] = {root, parent[root].second};

    visited[children[node][i]] = true;

    liftingChildren(children[node][i], root, parent, children);

    visited[children[node][i]] = false;
  }
}

void solve() {
  map <string, int> nameMap;
  vector <pii> parent;
  vector <vector<int>> children;
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
      children.push_back({});
    }
    if(isBNew) {
      nameMap.insert({b, idx++});
      parent.push_back({-1, 1});
      children.push_back({});
    }

    int aRoot = getRoot(nameMap[a], parent), bRoot = getRoot(nameMap[b], parent);

    parent[bRoot].first = aRoot;
    parent[aRoot].second += parent[bRoot].second;
    liftingChildren(aRoot, aRoot, parent, children);

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