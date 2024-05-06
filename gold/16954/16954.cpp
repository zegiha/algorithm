#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int>> arr;
vector <pair <int, int>> wall;

void addToQ(queue <pair <int, int>>* q, vector <vector <bool>>* visit, int row, int col) {
  vector <pair <int, int>> space;
  space.push_back(make_pair(row, col));
  if(row + 1 < 8) {
    space.push_back(make_pair(row + 1, col));
    if(col + 1 < 8) space.push_back(make_pair(row + 1, col + 1));
    if(col - 1 >= 0) space.push_back(make_pair(row + 1, col - 1));
  }
  if(row - 1 >= 0) {
    space.push_back(make_pair(row - 1, col));
    if(col + 1 < 8) space.push_back(make_pair(row - 1, col + 1));
    if(col - 1 >= 0) space.push_back(make_pair(row - 1, col - 1));
  }
  if(col + 1 < 8) space.push_back(make_pair(row, col + 1));
  if(col - 1 >= 0) space.push_back(make_pair(row, col - 1));

  for(int i = 0; i < space.size(); i++) {
    int r = space[i].first, c = space[i].second;
    if(!(*visit)[r][c] && arr[r][c] == 0) {
      (*visit)[r][c] = true;
      q->push(space[i]);
    }
  }
}

void downWall() {
  vector <vector <int>> arrCpy;
  arrCpy.resize(9, vector <int> (9, 0));
  for(int i = 0; i < wall.size(); i++) {
    if(wall[i].first + 1 < 8) wall[i].first++;
    else wall[i].first = 8;
    
    if(wall[i].first < 8) {
      arrCpy[wall[i].first][wall[i].second] = arr[wall[i].first - 1][wall[i].second];
    }
  }
  arr = arrCpy;
}

void printing(int row, int col) {
  cout << "***********************\n";
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(i == row && j == col) cout << 'H';
      else if(arr[i][j] == 0) cout << '.';
      else cout << '#';
    }
    cout << endl;
  }
  cout << "\n\n";
}

int main() {
  arr.resize(9, vector <int> (9, 0));
  for(int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < s.size(); j++) {
      if(s[j] == '.') arr[i][j] = 0;
      else {
        arr[i][j] = 1;
        wall.push_back(make_pair(i, j));
      }
    }
  }

  queue <pair <int, int>> q;

  q.push(make_pair(7, 0));
  while(!q.empty()) {
    int size = q.size();
    vector <vector <bool>> visit;
    visit.resize(8, vector <bool> (8, 0));
    for(int t = 0; t < size; t++) {
      int row = q.front().first, col = q.front().second;
      q.pop();
      if(row == 0 && col == 7) {
        cout << 1;
        return 0;
      }
      if(arr[row][col] == 0) addToQ(&q, &visit, row, col);
      else visit[row][col] = false;
      // cout << row << "  ||  " << col << endl;
      // printing(row, col);
    }
    downWall();
    // printing(9, 9);
    // cout << "sdsd\n\n";
  }
  cout << 0;
}