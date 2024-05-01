#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector <vector <int>> arr;
vector <vector <bool>> fVisit, hVisit;

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
      for(int j = 0; j < m; j++) if(arr[i][j] == 1) arr[i][j] = 2;
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
    }
  }
}

int main() {
  queue <pair <int, int>> f;

  cin >> n >> m;
  arr.resize(n + 1, vector <int> (m + 1, -1));
  fVisit.resize(n + 1, vector <bool> (m + 1, false));
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for(int j = 0; j < tmp.size(); j++) {
      if(tmp[j] == '#') arr[i][j] = 0;
      if(tmp[j] == '.') arr[i][j] = 1;
      if(tmp[j] == 'J') {
        arr[i][j] = 3;
      }
      if(tmp[j] == 'F') {
        arr[i][j] = 4;
        f.push(make_pair(i, j));
        fVisit[i][j] = true;
      }
    }
  }
  processing();

  while(!f.empty()) {
    int size = f.size();
    for(int t = 0; t < size; t++) {
      int row = f.front().first, col = f.front().second;
      arr[row][col] = 4;
      f.pop();
      addToQ(&f, &fVisit, row, col, true);
    }
    printing();
  }
  printing();
    for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << fVisit[i][j];
    }
    cout << endl;
  }
}