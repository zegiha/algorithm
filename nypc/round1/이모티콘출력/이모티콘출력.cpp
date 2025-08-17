#include <iostream>
#include <string>
#include <stack>

using namespace std;

int en, cn;
string ea[10], s;

bool isE(int start, int end) {
  string tmp = "";
  for(int i = start + 1; i < end; i++) tmp += s[i];
  for(auto e : ea) {
    if(e == tmp) return true;
  }
  return false;
}

int main() {
  cin >> en >> cn;
  for(int i = 0; i < en; i++) {
    cin >> ea[i];
  }
  cin >> s;
  
  stack <int> stack;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != ':') continue;
    if(stack.size() > 0) {
      if(stack.top() + 1 == i) {
        stack.pop();
        stack.push(i);
      } else {
        if(isE(stack.top(), i)) {
          s[stack.top()] = '[';
          s[i] = ']';
          stack.pop();
        } else {
          stack.pop();
          stack.push(i);
        }
      }
    } else {
      stack.push(i);
    }
  }

  // cout << s << '\n';

  int i = 0, charOut = 0;
  while(i < s.size()) {
    if(s[i] == '[') {
      while(s[i] != ']') {
        cout << s[i];
        i++;
      }
    }
    cout << s[i];
    i++;
    charOut++;
    if(charOut == cn) {
      charOut = 0;
      cout << '\n';
    }
  }
}