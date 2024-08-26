#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> f, s;

int main() {
  cin >> n;
  if(n == 2) {
    cout << "1\n1\n1\n2";
    return 0;
  }
  
  bool sw = true;
  int i = n;
  while(n > 2) {
    if(sw) {
      f.push_back(i); i--;

      s.push_back(i); i--;
      s.push_back(i); i--;
      
      sw = false;
    } else{
      s.push_back(i); i--;

      f.push_back(i); i--;
      f.push_back(i); i--;
      
      sw = false;
    }

    n -= 3;
  }
  if(n == 2) {
    s.push_back(2);
    f.push_back(1);
  }

  cout << f.size() << '\n';
  for(int i = 0; i < f.size(); i++) cout << f[i] << ' ';
  cout << '\n';

  cout << s.size() << '\n';
  for(int i = 0; i < s.size(); i++) cout << s[i] << ' ';
}