#include <iostream>
#include <string>

using namespace std;

int n;

int toNumber(string s) {
  int res = 0;
  for(int i = 0; i < s.size(); i++) {
    res *= 10;
    res += s[i] - '0';
  }

  return res;
}

int getPow(int exponent) {
  if(exponent <= 0) return 1;
  return 3 * getPow(exponent - 1);
}

string backtrack(int depth) {
  if(depth == 0) {
    return "-";
  }
  
  string blank;
  for(int i = 0; i < getPow(depth - 1); i++) {
    blank += " ";
  }
  return backtrack(depth - 1) + blank + backtrack(depth - 1);
}

int main() {
  while(true) {
    string s;
    getline(cin, s);
    
    if (s.empty()) break;
    
    n = toNumber(s);
    cout << backtrack(n) << '\n';
  }
}