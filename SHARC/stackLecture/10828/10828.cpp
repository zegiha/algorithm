#include <iostream>
#include <stack>

using namespace std;

int main() {
  string directions[5] = {"push", "pop", "size", "empty", "top"};
  stack <int> s;
  int t; cin >> t;
  while(t--) {
    string direction; cin >> direction;
    for(int i = 0; i < 5; i++) {
      if(directions[i] == direction) {
        switch (i)
        {
        case 0:
          int tmp; cin >> tmp;
          s.push(tmp);
          break;
        case 1:
          if(s.size() > 0) {
            cout << s.top() << endl;
            s.pop();
          } else {
            cout << -1 << endl;
          }
          break;
        case 2:
          cout << s.size() << endl;
          break;
        case 3:
          cout << s.empty() << endl;
          break;
        case 4:
          if(s.size() > 0) {
            cout << s.top() << endl;
          } else {
            cout << -1 << endl;
          }
          break;
        }
        break;
      }
    }
  }
}