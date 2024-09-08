#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[5][5], ans;

bool record[25];

pair <int, int> getCoordinate(int index) {
  return {index / 5, index % 5};
}

bool isDasom() {
  int cnt = 0, tryIndex = 0;
  while(cnt < 4 && tryIndex < 25) {
    if(record[tryIndex]) {
      int row = getCoordinate(tryIndex).first, col = getCoordinate(tryIndex).second;
      if(arr[row][col] == 0) cnt++; 
    }
    tryIndex++;
  }
  return cnt < 4;
}

bool isArea(int row, int col) {
  return row >= 0 && row < 5 && col >= 0 && col < 5;
}
bool isAdjust(int index) {
  queue <pair <int, int>> q;
  bool visit[5][5] = {0,};
  int
    cnt = 0,
    row = getCoordinate(index).first,
    col = getCoordinate(index).second,
    dy[] = {0, 0, 1, -1},
    dx[] = {1, -1, 0, 0},
    newRow, newCol;

  q.push({row, col});
  visit[row][col] = true;
  cnt++;

  while(!q.empty()) {
    row = q.front().first; col = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      newRow = row + dy[i]; newCol = col + dx[i];
      if(isArea(newRow, newCol) && !visit[newRow][newCol] && record[newRow * 5 + newCol]) {
        q.push({newRow, newCol});
        visit[newRow][newCol] = true;
        cnt++;
      }
    }
  }
  
  return cnt == 7;
}

void solve(int last, int depth) {
  if(depth == 7) {
    if(isDasom() && isAdjust(last)) {
      ans++;
      // for(int i = 0; i <= 25; i++) {
      //   pair <int, int> cdn = getCoordinate(i);
      //   if(record[i]) cout << 'C';
      //   else {
      //     if(arr[cdn.first][cdn.second]) cout << 'S';
      //     else cout << 'Y';
      //   }
      //   if(i % 5 == 0 && i ) cout << '\n';
      // }
      // cout << "\n=============================================\n";
    }
    return;
  }
  
  for(int i = last; i < 25; i++) {
    if(record[i]) continue;
    record[i] = true;
    solve(i, depth + 1);
    record[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      char t; cin >> t;
      if(t == 'S') arr[i][j] = 1;
      else arr[i][j] = 0;
    }
  }

  solve(0, 0);
  cout << ans;
}

