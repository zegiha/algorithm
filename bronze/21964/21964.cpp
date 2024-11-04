#include <iostream>

using namespace std;

int main() {
  string str; int n; cin >> n >> str;
  for(int i = str.size() - 5; i < str.size(); i++) cout << str[i];
}