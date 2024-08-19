#include <iostream>
#include <string>

using namespace std;

bool solve(string str) {
  int i = 0, tmp;
  if(str[i] != '1') return false; i++;
  if(str[i] != '0') return false; i++;
  if(str[i] == '0') return false;
  else tmp = str[i] - '0';
  i++;

  for(; i < str.size(); i++) {
    tmp *= 10;
    tmp += str[i] - '0';
  }

  // cout << tmp << '\n';
  if(tmp >= 2) return true;
  else return false;
}

int main() {
  int t; cin >> t;
  while(t--) {
    string str; cin >> str;
    if(solve(str)) cout << "yes\n";
    else cout << "no\n";
  }
}