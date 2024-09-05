#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector <int> record;
void backtrack(int used, int last) {
  if(used == m) {
    for(int i = 0; i < m; i++) {
      cout << record[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i = last + 1; i <= n; i++) {
    record.push_back(i);
    backtrack(used + 1, i);
    record.pop_back();
  }
}

int main() {
  cin >> n >> m;
  backtrack(0, 0);
}