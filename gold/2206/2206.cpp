#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans = 1;
vector <vector <int>> arr;

void addToQ(queue <pair <pair <int, int>, int>>* q, vector <vector <vector <bool>>>* visit, int row, int col, int isBreak) {
  vector <pair <pair <int, int>, int>> add;
  if(row + 1 < n) {
    if(arr[row + 1][col] == 0 && !(*visit)[row + 1][col][isBreak]) add.push_back(make_pair(make_pair(row + 1, col), isBreak));
    else if(!isBreak && !(*visit)[row + 1][col][1]) add.push_back(make_pair(make_pair(row + 1, col), isBreak + 1));
  }
  if(row - 1 >= 0) {
    if(arr[row - 1][col] == 0 && !(*visit)[row - 1][col][isBreak]) add.push_back(make_pair(make_pair(row - 1, col), isBreak));
    else if(!isBreak && !(*visit)[row - 1][col][1]) add.push_back(make_pair(make_pair(row - 1, col), isBreak + 1));
  }
  if(col + 1 < m) {
    if(arr[row][col + 1] == 0 && !(*visit)[row][col + 1][isBreak]) add.push_back(make_pair(make_pair(row, col + 1), isBreak));
    else if(!isBreak && !(*visit)[row][col + 1][1]) add.push_back(make_pair(make_pair(row, col + 1), isBreak + 1));
  }
  if(col - 1 >= 0) {
    if(arr[row][col - 1] == 0 && !(*visit)[row][col - 1][isBreak]) add.push_back(make_pair(make_pair(row, col - 1), isBreak));
    else if(!isBreak && !(*visit)[row][col - 1][1]) add.push_back(make_pair(make_pair(row, col - 1), isBreak + 1));
  }

  for(int i = 0; i < add.size(); i++) {
    int r = add[i].first.first, c = add[i].first.second, b = add[i].second;
    (*visit)[r][c][b] = true;
    q->push(make_pair(make_pair(r, c), b));
  }
}

int main() {
  cin >> n >> m;
  arr.resize(n + 1, vector <int> (m + 1));
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for(int j = 0; j < tmp.size(); j++) {
      arr[i][j] = tmp[j] - '0';
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) cout << arr[i][j];
  //   cout << endl;
  // }

  vector <vector <vector <bool>>> visit;
  visit.resize(n + 1, vector <vector <bool>> (m + 1, vector <bool> (2, false)));
  queue <pair <pair <int, int>, int>> q;
  if(arr[0][0] != 1) {
    visit[0][0][0] = true;
    q.push(make_pair(make_pair(0, 0), 0));
  } else {
    visit[0][0][1] = true;
    q.push(make_pair(make_pair(0, 0), 1));
  }
  while(!q.empty()) {
    int size = q.size();
    for(int t = 0; t < size; t++) {
      int row = q.front().first.first, col = q.front().first.second, isBreak = q.front().second;
      q.pop();
      if(row == n - 1 && col == m - 1) {
        cout << ans;
        return 0;
      }
      addToQ(&q, &visit, row, col, isBreak);
    }
    ans++;
  }
  cout << -1;
}