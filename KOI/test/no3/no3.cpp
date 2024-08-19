#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isIn(vector <pair <int, bool>>* same, int compare) {
  for(int i = 0; i < same->size(); i++) {
    if((*same)[i].second && (*same)[i].first == compare) return true;
  }

  return false;
}

void solve() {
  int n; cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  int m; cin >> m;
  while(m--) {
    bool sw = true;
    string str;
    cin >> str;
    if(str.size() != n) {
      cout << "no\n";
      continue;
    }

    vector <int> check;
    vector <pair <int, bool>> same (26, {0, false});
    for(int i = 0; i < str.size(); i++) {
      int index = str[i] - 'a';
      if(!same[index].second) {
        if(isIn(&same, arr[i])) {
          cout << "no\n";
          sw = false;
          break;
        }
        same[index].first = arr[i];
        same[index].second = true;
      }
      else {
        if(same[index].first != arr[i]) {
          cout << "no\n";
          sw = false;
          break;
        }
      }
    }

    // cout << "-----------------------\n";
    // for(int i = 0; i < same.size(); i++) {
    //   cout << same[i].first << "  ||  " << same[i].second << '\n';
    // }
    // cout << "-----------------------\n";
    
    if(sw) cout << "yes\n";
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}
/*
1
2
1 1
2
az
*/