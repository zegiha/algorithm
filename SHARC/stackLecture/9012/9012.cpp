#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    bool sw = true;
    stack <int> s;
    string str; cin >> str;
    for(int i = 0; i < str.length(); i++) {
      if(str[i] == '(') {
        s.push(1);
      } else {
        if(!s.empty()) {
          s.pop();
        } else {
          sw = false;
        }
      }
    }
    // cout << t << ":  " << sw << "  ||  " << s.empty() << endl;
    if(sw && s.empty()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}