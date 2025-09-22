#include <iostream>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int n, q, originalParent[200'001], parent[200'001];
vector <int> ans;
vector <pii> queries;

int Find(int a) {
  if(parent[a] == a) return a;
  return parent[a] = Find(parent[a]);
}

void Union(int p, int c) {
  int pRoot = Find(p), cRoot = Find(c);

  if(pRoot == cRoot) return;

  parent[pRoot] = cRoot;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for(int i = 2; i <= n; i++) {
    cin >> originalParent[i];
  }

  int x, a, b;
  for(int i = 0; i < (n-1) + q; i++) {
    cin >> x;
    if(x == 0) {
      cin >> a;
      queries.push_back({a, -1});
    } else {
      cin >> a >> b;
      queries.push_back({a, b});
    }
  }

  for(int i = 1; i <= n; i++) parent[i] = i;


  for(int i = queries.size()-1; i >= 0; i--) {
    pii query = queries[i];


    if(query.second == -1) {
      // Union
      Union(query.first, originalParent[query.first]);
    } else {
      int fRoot = Find(query.first), sRoot = Find(query.second);

      if(fRoot == sRoot) ans.push_back(1);
      else ans.push_back(0);
    }
  }


  for(int i = ans.size()-1; i >=0; i--) cout << (ans[i] ? "YES" : "NO") << '\n';
}
