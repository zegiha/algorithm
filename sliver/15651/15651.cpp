#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector <int> record;
void backtrack(int depth) {
  if(depth == m) {
    for(int i = 0; i < m; i++) {
      cout << record[i] << ' ';
    } cout << '\n';
    return;
  }

  for(int i = 1; i <= n; i++) {
    record.push_back(i);
    backtrack(depth + 1);
    record.pop_back();
  }
}

int main() {
  cin >> n >> m;
  backtrack(0);
}