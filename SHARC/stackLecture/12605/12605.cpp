#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main() {
  int t; cin >> t;

  cin.ignore();
  for(int i = 1; i <= t; i++) {
    stack <string> s;
    string input, word;
    getline(cin, input);
    
    istringstream iss(input);
    while(iss >> word) {
      s.push(word);
    }
    
    cout << "Case #" << i << ": ";
    while(!s.empty()) {
      cout << s.top() << ' ';
      s.pop();
    }
    cout << endl;
  }
}