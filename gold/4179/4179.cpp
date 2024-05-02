#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector <vector <int>> arr;
vector <vector <bool>> fVisit, hVisit;
bool isOut = false;

void printing() {
  cout << "\n*******************************\n\n";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(arr[i][j] == 1) cout << '.';
      if(arr[i][j] == 0) cout << '#';
      if(arr[i][j] == 3) cout << 'H';
      if(arr[i][j] == 4) cout << 'F';
      if(arr[i][j] == 2) cout << 'G';
    }
    cout << endl;
  }
  cout << endl;
}

void processing() {
  for(int i = 0; i < n; i++) {
    if(i == 0 || i == n - 1) {
      for(int j = 0; j < m; j++) {
        if(arr[i][j] == 3) isOut = true;
        if(arr[i][j] == 1) arr[i][j] = 2;
      }
    } else {
      if(arr[i][0] == 3) isOut = true;
      if(arr[i][0] == 1) arr[i][0] = 2;
      if(arr[i][m - 1] == 3) isOut = true;
      if(arr[i][m - 1] == 1) arr[i][m - 1] = 2;
    }
  }
}

void addToQ(queue <pair <int, int>>* q, vector <vector <bool>>* visit, int row, int col, bool isF) {
  if (row + 1 < n) {
    if(
      (arr[row + 1][col] > 0) && (arr[row + 1][col] < arr[row][col])
      && !(*visit)[row + 1][col]
    ) {
      q->push(make_pair(row + 1, col));
      (*visit)[row + 1][col] = true;
      if(isF) hVisit[row + 1][col] = true;
      else if(arr[row + 1][col] == 2) isOut = true;
    }
  }
  if (row - 1 >= 0) {
    if(
      (arr[row - 1][col] > 0) && (arr[row - 1][col] < arr[row][col])
      && !(*visit)[row - 1][col]
    ) {
      q->push(make_pair(row - 1, col));
      (*visit)[row - 1][col] = true;
      if(isF) hVisit[row - 1][col] = true;
      else if(arr[row - 1][col] == 2) isOut = true;
    }
  }
  if (col + 1 < m) {
    if(
      (arr[row][col + 1] > 0) && (arr[row][col + 1] < arr[row][col])
      && !(*visit)[row][col + 1]
    ) {
      q->push(make_pair(row, col + 1));
      (*visit)[row][col + 1] = true;
      if(isF) hVisit[row][col + 1] = true;
      else if(arr[row][col + 1] == 2) isOut = true;
    }
  }
  if (col - 1 >= 0) {
    if(
      (arr[row][col - 1] > 0) && (arr[row][col - 1] < arr[row][col])
      && !(*visit)[row][col - 1]
    ) {
      q->push(make_pair(row, col - 1));
      (*visit)[row][col - 1] = true;
      if(isF) hVisit[row][col - 1] = true;
      else if(arr[row][col - 1] == 2) isOut = true;
    }
  }
}

int main() {
  queue <pair <int, int>> f, h;

  cin >> n >> m;
  arr.resize(n + 1, vector <int> (m + 1, -1));
  fVisit.resize(n + 1, vector <bool> (m + 1, false));
  hVisit.resize(n + 1, vector <bool> (m + 1, false));
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for(int j = 0; j < tmp.size(); j++) {
      if(tmp[j] == '#') arr[i][j] = 0;
      if(tmp[j] == '.') arr[i][j] = 1;
      if(tmp[j] == 'J') {
        arr[i][j] = 3;
        h.push(make_pair(i, j));
        hVisit[i][j] = true;
      }
      if(tmp[j] == 'F') {
        arr[i][j] = 4;
        f.push(make_pair(i, j));
        fVisit[i][j] = true;
        hVisit[i][j] = true;
      }
    }
  }
  processing();

  ans = 1;
  if(isOut) {
    cout << ans;
    return 0;
  }
  while((!f.empty() || !h.empty())) {
    int size = f.size();
    for(int t = 0; t < size; t++) {
      int row = f.front().first, col = f.front().second;
      arr[row][col] = 4;
      f.pop();
      addToQ(&f, &fVisit, row, col, true);
    }
    size = h.size();
    for(int t = 0; t < size; t++) {
      int row = h.front().first, col = h.front().second;
      arr[row][col] != 4 ? arr[row][col] = 3 : arr[row][col];
      h.pop();
      addToQ(&h, &hVisit, row, col, false);
    }
    
    if(isOut) {
      cout << ans + 1;
      return 0;
    }
    ans++;
  }
  cout << "IMPOSSIBLE";
}
