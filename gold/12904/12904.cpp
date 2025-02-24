#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string from, to;

int main() {
  cin >> from >> to;

  while(from.size() < to.size()) {
    if(to[to.size()-1] == 'A') {
      to.pop_back();
    } else {
      to.pop_back();
      reverse(to.begin(), to.end());
    }
  }

  if(from == to) cout << 1;
  else cout << 0;
}
