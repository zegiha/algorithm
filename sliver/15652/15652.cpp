#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector <int> record;
void backtrack(int depth, int last) {
  if(depth == m) {
    for(int i = 0; i < m; i++) cout << record[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = last; i <= n; i++) {
    record.push_back(i);
    backtrack(depth + 1, i);
    record.pop_back();
  }
}

int main() {
  cin >> n >> m;
  backtrack(0, 1);
}