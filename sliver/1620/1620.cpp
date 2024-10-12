#include <iostream>
#include <map>
#include <string>

using namespace std;

string id[100'001];
map <string, int> name;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    string str; cin >> str;
    id[i] = str;
    name.insert({str, i});
  }

  while(m--) {
    string str; cin >> str;
    if('0' <= str[0] && str[0] <= '9') {
      cout << id[stoi(str)] << '\n';
    } else {
      cout << name[str] << '\n';
    }
  }

  return 0;
}