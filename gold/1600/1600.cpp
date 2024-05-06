#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k, w, h, ans;
vector <vector <int>> arr;

void addToQ(queue <pair <pair<int, int>, int>>* q, vector <vector <vector <bool>>>* visit, int row, int col, int sum) {
  if(row + 1 < h) {
    if(arr[row + 1][col] != 1 && !(*visit)[row + 1][col][sum]) {
      (*visit)[row + 1][col][sum] = true;
      q->push(make_pair(make_pair(row + 1, col), sum));
    }
    
    if(col + 2 < w && sum + 1 <= k) {
      if(arr[row + 1][col + 2] != 1 && !(*visit)[row + 1][col + 2][sum + 1]) {
        (*visit)[row + 1][col + 2][sum + 1] = true;
        q->push(make_pair(make_pair(row + 1, col + 2), sum + 1));
      }
    }
    if(col - 2 >= 0 && sum + 1 <= k) {
      if(arr[row + 1][col - 2] != 1 && !(*visit)[row + 1][col - 2][sum + 1]) {
        (*visit)[row + 1][col - 2][sum + 1] = true;
        q->push(make_pair(make_pair(row + 1, col - 2), sum + 1));
      }
    }
  }
  if(row - 1 >= 0) {
    if(arr[row - 1][col] != 1 && !(*visit)[row - 1][col][sum]) {
      (*visit)[row - 1][col][sum] = true;
      q->push(make_pair(make_pair(row - 1, col), sum));
    }

    if(col + 2 < w && sum + 1 <= k) {
      if(arr[row - 1][col + 2] != 1 && !(*visit)[row - 1][col + 2][sum + 1]) {
        (*visit)[row - 1][col + 2][sum + 1] = true;
        q->push(make_pair(make_pair(row - 1, col + 2), sum + 1));
      }
    }
    if(col - 2 >= 0 && sum + 1 <= k) {
      if(arr[row - 1][col - 2] != 1 && !(*visit)[row - 1][col - 2][sum + 1]) {
        (*visit)[row - 1][col - 2][sum + 1] = true;
        q->push(make_pair(make_pair(row - 1, col - 2), sum + 1));
      }
    }
  }
  if(col + 1 < w) {
    if(arr[row][col + 1] != 1 && !(*visit)[row][col + 1][sum]) {
      (*visit)[row][col + 1][sum] = true;
      q->push(make_pair(make_pair(row, col + 1), sum));
    }

    if(row + 2 < h && sum + 1 <= k) {
      if(arr[row + 2][col + 1] != 1 && !(*visit)[row + 2][col + 1][sum + 1]) {
        (*visit)[row + 2][col + 1][sum + 1] = true;
        q->push(make_pair(make_pair(row + 2, col + 1), sum + 1));
      }
    }
    if(row - 2 >= 0 && sum + 1 <= k) {
      if(arr[row - 2][col + 1] != 1 && !(*visit)[row - 2][col + 1][sum + 1]) {
        (*visit)[row - 2][col + 1][sum + 1] = true;
        q->push(make_pair(make_pair(row - 2, col + 1), sum + 1));
      }
    }
  }
  if(col - 1 >= 0) {
    if(arr[row][col - 1] != 1 && !(*visit)[row][col - 1][sum]) {
      (*visit)[row][col - 1][sum] = true;
      q->push(make_pair(make_pair(row, col - 1), sum));
    }

    if(row + 2 < h && sum + 1 <= k) {
      if(arr[row + 2][col - 1] != 1 && !(*visit)[row + 2][col - 1][sum + 1]) {
        (*visit)[row + 2][col - 1][sum + 1] = true;
        q->push(make_pair(make_pair(row + 2, col - 1), sum + 1));
      }
    }
    if(row - 2 >= 0 && sum + 1 <= k) {
      if(arr[row - 2][col - 1] != 1 && !(*visit)[row - 2][col - 1][sum + 1]) {
        (*visit)[row - 2][col - 1][sum + 1] = true;
        q->push(make_pair(make_pair(row - 2, col - 1), sum + 1));
      }
    }
  }
}

int main() {
  cin >> k >> w >> h;
  arr.resize(h + 1, vector <int> (w + 1));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) cin >> arr[i][j];
  }

  vector <vector <vector <bool>>> visit;
  visit.resize(h + 1, vector <vector <bool>> (w + 1, vector <bool> (k + 1, false)));
  queue <pair <pair <int, int>, int>> q;
  visit[0][0][0] = true;
  q.push(make_pair(make_pair(0, 0), 0));
  while(!q.empty()) {
    int size = q.size();
    for(int t = 0; t < size; t++) {
      int row = q.front().first.first, col = q.front().first.second, sum = q.front().second;
      if(row == h - 1 && col == w - 1) {
        cout << ans;
        return 0;
      }
      q.pop();
      addToQ(&q, &visit, row, col, sum);
    }
    ans++;
  }
  cout << -1;
}