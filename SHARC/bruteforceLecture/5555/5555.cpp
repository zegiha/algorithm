#include <iostream>
#include <string>

using namespace std;

int ans;
string lettering;

bool isSame(string str, int start) {
  int i = start, end = start + lettering.size();
  while(i < end) {
    // cout << i % (str.size()) << ' ' << str[i % (str.size() - 1)] << ' ';
    if(str[i % (str.size())] != lettering[i - start]) return false;
    // cout << "hehe..";
    i++;
  }
  return true;
}

bool hasStr(string str) {
  int size = lettering.size() - 1;
  for(int i = 0; i < str.size(); i++) {
    if(isSame(str, i)) return true;
  }
  return false;
}

int main() {
  int t;
  cin >> lettering >> t;
  while(t--) {
    string str; cin >> str;
    if(hasStr(str)) ans++;
  }
  cout << ans++;
  // string s1 = "abcde";
  // string s2 = "ab";
  // cout << s1.compare(0, 1, s2);
}