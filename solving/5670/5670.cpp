#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

int n;
vector <string> arr;

struct Trie {
  int childrenCnt = 0;
  bool finish = false;
  Trie* arr[26] = {};

  ~Trie() {
    for(int i = 0; i < 26; i++) 
      if(arr[i]) delete arr[i];
  }

  int insert(string& str, int idx) {
    if(str.size() == idx) {
      finish = true;
      return 1;
    }
    int target = str[idx] - 'a';
    if(arr[target] == NULL) {
      arr[target] = new Trie();
    }
    return childrenCnt += arr[target]->insert(str, idx + 1);
  }

  int getClickCnt(string& str, int idx) {
    cout << childrenCnt << ' ' << str[idx] << "  ||  ";
    if(childrenCnt <= 1) return 1;
    else return 1 + arr[str[idx]-'a']->getClickCnt(str, idx + 1);
  }
};

void input() {
  string input;

  for(int i = 0; i < n; i++) {
    cin >> input;
    arr.push_back(input);
  }
}

int main() {
  while(cin >> n) {
    input();
    Trie* trie = new Trie();

    for(int i = 0; i < n; i++) {
      trie->insert(arr[i], 0);
    }

    double cnt = 0;
    for(int i = 0; i < n; i++) {
      int res = trie->getClickCnt(arr[i], 0);
      cout << res << '\n';
      cnt += (double)(res);
    }

    printf("%.2lf\n", cnt / (double)n);

    delete trie;
  }
}