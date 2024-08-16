#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Shark {
  int row;
  int col;
  int size;
  int eaten;
};
struct Prey
{
  int row;
  int col;
  int cnt;
};


int n, fishCnt, ans;
Shark shark = {0, 0, 2, 0};
vector <vector <int>> arr;

bool isInArea(int req) {
  if(req >= 0 && req < n) return true;
  return false;
}
Prey getPrey() {
  Prey res = {-1, -1, 0};
  vector <Prey> candidates;
  int row = shark.row, col = shark.col, cnt = 1;
  vector <vector <bool>> visit(n, vector <bool> (n, false));
  visit[row][col] = true;
  queue <pair <int, int>> q;
  q.push({row, col});

  while(!q.empty()) {
    int size = q.size();
    while(size--) {
      row = q.front().first; col = q.front().second;
      q.pop();
      
      if(isInArea(row - 1)) if(!visit[row - 1][col] && shark.size >= arr[row - 1][col]) {
        if(shark.size > arr[row - 1][col] && arr[row - 1][col] > 0) candidates.push_back({row - 1, col, cnt});
        else {
          q.push({row - 1, col});
          visit[row - 1][col] = true;
        }
      }
      if(isInArea(col - 1)) if(!visit[row][col - 1] && shark.size >= arr[row][col - 1]) {
        if(shark.size > arr[row][col - 1] && arr[row][col - 1] > 0) candidates.push_back({row, col - 1, cnt});
        else {
          q.push({row, col - 1});
          visit[row][col - 1] = true;
        }
      }
      if(isInArea(col + 1)) if(!visit[row][col + 1] && shark.size >= arr[row][col + 1]) {
        if(shark.size > arr[row][col + 1] && arr[row][col + 1] > 0) candidates.push_back({row, col + 1, cnt});
        else {
          q.push({row, col + 1});
          visit[row][col + 1] = true;
        }
      }
      if(isInArea(row + 1)) if(!visit[row + 1][col] && shark.size >= arr[row + 1][col]) {
        if(shark.size > arr[row + 1][col] && arr[row + 1][col] > 0) candidates.push_back({row + 1, col, cnt});
        else {
          q.push({row + 1, col});
          visit[row + 1][col] = true;
        }
      }
    }
    cnt++;
    if(!candidates.empty()) break;
  }

  if (!candidates.empty()) {
    sort(candidates.begin(), candidates.end(), [](const Prey &a, const Prey &b) {
      if (a.row == b.row) return a.col < b.col;
      return a.row < b.row;
    });
    res = candidates.front();
  }

  return res;
}

int main() {
  cin >> n; arr.resize(n, vector <int> (n, 0));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
    cin >> arr[i][j];
    if(arr[i][j] == 9) {
      shark.row = i;
      shark.col = j;
      arr[i][j] = 0;
    } else if(arr[i][j] != 0) fishCnt++;
  }

  while(true) {
    if(fishCnt <= 0) break;
    Prey prey = getPrey();
    if(prey.row == -1) break;

    arr[prey.row][prey.col] = 0;

    ans += prey.cnt;
    shark.row = prey.row;
    shark.col = prey.col;
    shark.eaten++;
    fishCnt--;
    if(shark.eaten == shark.size) {
      shark.eaten = 0;
      shark.size++;
    }
  }

  cout << ans;
}