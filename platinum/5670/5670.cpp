#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

int n;
vector <string> arr;

struct Trie {
  bool finish = false;
  int childrenCnt = 0, finishCnt = 0;
  Trie* arr[26] = {};

  ~Trie() {
    for(int i = 0; i < 26; i++) 
      if(arr[i]) delete arr[i];
  }

  void insert(string& str, int idx) {
    finishCnt++;
    if(str.size() == idx) {
      finish = true;
      return;
    }
    
    int target = str[idx] - 'a';

    if(arr[target] == NULL) {
      childrenCnt++;
      arr[target] = new Trie();
    }

    arr[target]->insert(str, idx + 1);
  }

  int getClickCnt(string& str, int idx) {
    // cout << str[idx] << ' ' << finishCnt << ' ' << childrenCnt << "  ||  ";
    if(str.size() == idx) return 0;
    if(finishCnt <= 1) {
      if(idx == 0) return 1;
      return 0;
    }

    int target = str[idx] - 'a';

    if(childrenCnt <= 1 && !finish && 0 < idx) 
      return arr[target]->getClickCnt(str, idx + 1);
    else
      return 1 + arr[target]->getClickCnt(str, idx + 1);
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(cin >> n) {
    input();
    Trie* trie = new Trie();

    for(int i = 0; i < n; i++) {
      trie->insert(arr[i], 0);
    }

    double cnt = 0;
    for(int i = 0; i < n; i++) {
      // cout << arr[i] << " : ";
      int res = trie->getClickCnt(arr[i], 0);
      // cout << res << '\n';
      cnt += (double)(res);
    }

    double ans = cnt / (double)n * 100.0;
    ans = round(ans);
    ans /= 100.0;

    printf("%.2lf\n", ans);

    delete trie;
    arr.clear();
  }
}