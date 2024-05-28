#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, limit, ans;
vector <vector <int>> arr, map;

struct compare{
  bool operator() (pair <pair <int, int>, pair <int, int>> a, pair <pair <int, int>, pair <int, int>> b){
    if(!(a.second.first == b.second.first)) return a.second.first < b.second.first;
    else if (!(a.second.second == b.second.second)) return a.second.second < b.second.second;
    else if(!(a.first.first == b.first.first)) return a.first.first > b.first.first;
    else return a.first.second > b.first.second;
  }
};

pair <int, int> getAdj(int e, int row, int col) {
  pair <int, int> res = make_pair(0, 0);
  if(row + 1 <= n) {
    if(map[row + 1][col] == 0) res.second++;
    else for(int i = 1; i <= 4; i++) if(map[row + 1][col] == arr[e][i]) {
      res.first++;
      break;
    }
  }
  if(row - 1 >= 1) {
    if(map[row - 1][col] == 0) res.second++;
    else for(int i = 1; i <= 4; i++) if(map[row - 1][col] == arr[e][i]) {
      res.first++;
      break;
    }
  }
  if(col + 1 <= n) {
    if(map[row][col + 1] == 0) res.second++;
    else for(int i = 1; i <= 4; i++) if(map[row][col + 1] == arr[e][i]) {
      res.first++;
      break;
    }
  }
  if(col - 1 >= 1) {
    if(map[row][col - 1] == 0) res.second++;
    else for(int i = 1; i <= 4; i++) if(map[row][col - 1] == arr[e][i]) {
      res.first++;
      break;
    }
  }
  return res;
}

void seat(int e) {
  priority_queue<pair <pair <int, int>, pair <int, int>>, vector<pair <pair <int, int>, pair <int, int>>>, compare> q;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(map[i][j] == 0) {
        pair <pair <int, int>, pair <int, int>> pushE;
        pushE.first.first = i; pushE.first.second = j;
        pushE.second = getAdj(e, i, j);
        q.push(pushE);
      }
    }
  }
  map[q.top().first.first][q.top().first.second] = e;
}

int main() {
  cin >> n; limit = n * n;
  arr.resize(limit + 1, vector <int> (4, 0));
  map.resize(n + 1, vector <int> (n + 1, 0));

  for(int i = 0; i < limit; i++) {
    int index;
    cin >> index;
    for(int t = 1; t <= 4; t++) cin >> arr[index][t];
    seat(index);
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int adj = getAdj(map[i][j], i, j).first;
      switch(adj) {
        case(1):
          ans += 1;
          break;
        case(2):
          ans += 10;
          break;
        case(3):
          ans += 100;
          break;
        case(4):
          ans += 1000;
      }
    }
  }
  cout << ans;
}