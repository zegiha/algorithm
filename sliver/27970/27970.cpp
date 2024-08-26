#include <iostream>

using namespace std;

int main() {
  unsigned long long ans = 0, sum = 1;
  string str;
  cin >> str;

  for(int i = 0; i < str.size(); i++) {
    if(str[i] == 'O') {
      ans = (ans + sum) % 1000000007;
    }
    sum = (sum * 2) % 1000000007;
  }

  cout << ans;
}