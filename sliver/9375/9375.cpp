#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int getTypeIdx(string newType, vector <string> type) {
  for(int i = 0; i < type.size(); i++) {
    if(type[i] == newType) return i;
  }
  return -1;
}

void solve() {
  int n;
  vector <string> type;
  vector <vector <string>> cloth;

  cin >> n;
  for(int i = 0; i < n; i++) {
    string newType, newCloth; cin >> newCloth >> newType;
    int idx = getTypeIdx(newType, type);
    if(idx == -1) {
      type.push_back(newType);
      cloth.push_back(vector <string> (1, newCloth));
    } else {
      cloth[idx].push_back(newCloth);
    }
  }


  int ans = 1;
  for(int i = 0; i < type.size(); i++) {
    ans *= cloth[i].size() + 1;
  }

  cout << ans -1 << '\n';
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}