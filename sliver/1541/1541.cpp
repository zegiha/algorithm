#include <iostream>
#include <string>

using namespace std;

int main() {
  string str; cin >> str;

  string newNumber;
  int ans = 0;
  bool sw = false;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] == '+' || str[i] == '-') {
      int n = stoi(newNumber);
      if(sw) {
        ans -= n;
      } else {
        ans += n;
        if(str[i] == '-') sw = true;
      }
      newNumber = "";
    } else {
      newNumber += str[i];
    }
  }
  int n = stoi(newNumber);
  if(sw) {
    ans -= n;
  } else {
    ans += n;
  }

  cout << ans;
}