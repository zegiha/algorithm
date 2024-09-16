#include <iostream>
#include <vector>

using namespace std;

int n, ans;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector <vector<int>> put;

bool isArea(int row, int col) {
  return row >= 0 && row < n && col >= 0 & col < n;
}
void setPut(int q, bool m) {
  int row = q / n, col = q % n;
  if(m) put[row][col]--;
  else put[row][col]++;
  for(int d = 0; d < 8; d++) {
    row = q / n; col = q % n;
    while(isArea(row + dy[d], col + dx[d])) {
      row += dy[d];
      col += dx[d];
      if(m) put[row][col]--;
      else put[row][col]++;
    }
  }
}

void backtrack(int depth, int last) {
  if(depth == n) {
    ans++;
    return;
  }

  for(int i = last + 1; i < n * n; i++) {
    if(put[i / n][i % n] == 0) {
      setPut(i, false);
      backtrack(depth + 1, i);
      setPut(i, true);
    }
  }
}

int main() {
  cin >> n; put.resize(n, vector<int> (n, 0));
  backtrack(0, -1);
  cout << ans;
}