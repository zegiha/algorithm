#include <iostream>
#include <string>

using namespace std;

bool isContraction(string temp) {
  for(int i = 10; i < temp.size() - 12; i++) {
    if(temp[i] == '.') return false;
  }
  return true;
}

int main() {
  int t; string str; cin >> t >> str;
  if(str.size() <= 25) {
    cout << str;
  } else {
    if(isContraction(str)) {
      for(int i = 0; i < 11; i++) {
        cout << str[i];
      }
      cout << "...";
      for(int i = str.size() - 11; i < str.size(); i++) {
        cout << str[i];
      }
    } else {
      for(int i = 0; i < 9; i++) {
        cout << str[i];
      }
      cout << "......";
      for(int i = str.size() - 10; i < str.size(); i++) {
        cout << str[i];
      }
    }
  }
}