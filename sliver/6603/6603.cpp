#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> s;

vector <int> record;
void backtrack(int used, int last) {
  if(used == 6) {
    for(int i = 0; i < 6; i++) {
      cout << record[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = last + 1; i < n; i++) {
    record.push_back(s[i]);
    backtrack(used + 1, i);
    record.pop_back();
  }
}

int main() {
  while(true) {
    cin >> n; if(n == 0) break;
    s.resize(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    backtrack(0, -1);
    cout << '\n';
  }
}