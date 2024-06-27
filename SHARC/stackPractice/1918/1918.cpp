#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

bool isHighPriority(char strE, char top) {
  if(top == '(' || strE == '(') return false;
  if((strE == '*'|| strE == '/') && (top == '+' || top == '-')) return false;
  return true;
}

bool isOpreator(char strE) {
  if(strE == '+' || strE == '-' || strE == '*' || strE == '/' || strE == '(' || strE == ')')  return true;
  else return false;
}

int main() {
  stack <char> s;
  cin >> str;
  for(int i = 0; i < str.size(); i++) {
    if(!isOpreator(str[i])) {
      cout << str[i];
      continue;
    }
    if(str[i] == ')') {
      while(s.top() != '(') {
        cout << s.top();
        s.pop();
      }
      s.pop();
    }
    else {
      while(!s.empty() && isHighPriority(str[i], s.top())) {
        cout << s.top();
        s.pop();
      }
      s.push(str[i]);
    }
  }

  while(!s.empty()) {
    if(isHighPriority(s.top(), s.top())) cout << s.top();
    s.pop();
  }
}