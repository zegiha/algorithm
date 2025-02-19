#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Trie {
  map <string, Trie*> m;

  void insert(vector <string>& v, int idx) {
    if(idx == v.size()) return;

    if(m.find(v[idx]) == m.end()) {
      Trie* trie = new Trie;
      m.insert({v[idx], trie});
    }

    m[v[idx]]->insert(v, idx + 1);
  }

  void dfs_and_clean_mem(int depth) {
    for(auto& i : m) {
      for(int j = 0; j < depth; j++) cout << "--";
      cout << i.first << '\n';

      i.second->dfs_and_clean_mem(depth + 1);
      delete i.second;
    }
  }
};

int main() {
  int t, n;
  Trie* root = new Trie;

  cin >> t;

  while(t--) {
    cin >> n;
    vector <string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    root->insert(v, 0);
  }

  root->dfs_and_clean_mem(0);
  delete root;
}