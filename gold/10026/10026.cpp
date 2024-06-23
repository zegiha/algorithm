#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, normal[3], RG[2];
vector <vector <int>> arr;
vector <vector <bool>> visit;

bool isSameSection(int e, int r, bool isRG) {
  if(isRG) {
    if((e != 3 && r != 3) || (e == 3 && r == 3)) return true;
    else false;
  } else {
    if(e == r) return true;
    else return false;
  }
}
void addToQ(int r, int c, int root, queue<pair<int, int>>* q, bool isRG) {
  if(r + 1 < n) if(isSameSection(arr[r + 1][c], root, isRG) && !visit[r + 1][c]) {
    visit[r + 1][c] = true;
    q->push({r + 1, c});
  }
  if(r - 1 >= 0) if(isSameSection(arr[r - 1][c], root, isRG) && !visit[r - 1][c]) {
    visit[r - 1][c] = true;
    q->push({r - 1, c});
  }
  if(c + 1 < n) if(isSameSection(arr[r][c + 1], root, isRG) && !visit[r][c + 1]) {
    visit[r][c + 1] = true;
    q->push({r, c + 1});
  }
  if(c - 1 >= 0) if(isSameSection(arr[r][c - 1], root, isRG) && !visit[r][c - 1]) {
    visit[r][c - 1] = true;
    q->push({r, c - 1});
  }
}

void countSection(int r, bool isRG) {
  if(isRG) {
    if(r != 3) RG[0]++;
    else RG[1]++;
  } else normal[r - 1]++;
}

void getSection(int r, int c, int root, bool isRG) {
  queue <pair<int, int>> q;
  q.push({r, c});
  visit[r][c] = true;
  while(!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    addToQ(r, c, root, &q, isRG);
  }
  countSection(root, isRG);

  // for(int i = 0 ; i < n; i++) {
  //   for(int j = 0; j < n; j++) cout << visit[i][j] << ' ';
  //   cout << endl;
  // }

}

int main() {
  cin >> n;
  arr.resize(n + 1, vector <int> (n + 1));
  visit.resize(n + 1, vector <bool> (n + 1, false));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      char t; cin >> t;
      if(t == 'R') arr[i][j] = 1;
      else if(t == 'G') arr[i][j] = 2;
      else arr[i][j] = 3;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visit[i][j]) {
        getSection(i, j, arr[i][j], false);
      }
    }
  }

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(arr[i][j] != 3) visit[i][j] = false;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visit[i][j]) {
        getSection(i, j, arr[i][j], true);
      }
    }
  }

  cout << normal[0] + normal[1] + normal[2] << ' ' << RG[0] + normal[2];
}