#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
map <string, vector <string>> arr;
map <string, string> arr2;
vector <string> key;

void solve() {
  int t;
  string s;
  cin >> s >> t;
  if(t) {
    cout << arr2[s] << '\n';
  } else {
    for(int i = 0; i < arr[s].size(); i++) {
      cout << arr[s][i] << '\n';
    }
  }
}

int main() {
  cin >> n >> m;
  string str; int t;
  for(int i = 0; i < n; i++) {
    cin >> str >> t;
    key.push_back(str);
    vector <string> v;
    while(t--) {
      cin >> str;
      v.push_back(str);
      arr2.insert({str, key[i]});
    }
    sort(v.begin(), v.end());
    arr.insert({key[i], v});
  }

  while(m--) {
    solve();
  }
}