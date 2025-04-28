#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Trie {
  map <char, pair <Trie*, string>> m;
  
  void insert(string& v, int idx) {
    if(m.find(v[idx]) == m.end()) {
      Trie* trie = new Trie;
      m.insert({v[idx], {trie, ""}});
    }
  }
};

int main() {

}