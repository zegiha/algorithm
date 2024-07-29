#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[501][501][501];
queue <vector <int>> q;

pair <int, int> getBS(int a, int b) { // big, small
  if(a > b) return {a, b};
  else return {b, a};
}

vector <int> getNewG(pair <int, int> bs, int item) {
  vector <int> res (3);

  res[0] = bs.first - bs.second;
  res[1] = bs.second * 2;
  res[2] = item;
  sort(res.begin(), res.end());

  return res;
}

void pushToQ(vector <int> newG) {
  if(!visit[newG[0]][newG[1]][newG[2]]) {
    q.push(newG);
    visit[newG[0]][newG[1]][newG[2]] = true;
  }
}

bool isOver(vector <int> newG) {
  return newG[0] == newG[1] && newG[1] == newG[2];
}

bool pushToQ_And_CheckIsOver(vector <int> g) {
  vector <int> newG;

  if(g[0] != g[1]) {
    newG = getNewG(getBS(g[0], g[1]), g[2]);
    pushToQ(newG);
    if(isOver(newG)) return true;
  }

  if(g[0] != g[2]) {
    newG = getNewG(getBS(g[0], g[2]), g[1]);
    pushToQ(newG);
    if(isOver(newG)) return true;
  }

    if(g[1] != g[2]) {
    newG = getNewG(getBS(g[1], g[2]), g[0]);
    pushToQ(newG);
    if(isOver(newG)) return true;
  }

  return false;
}

int main() {
  vector <int> g (3);
  cin >> g[0] >> g[1] >> g[2];

  if(pushToQ_And_CheckIsOver(g)) {
    cout << 1;
    return 0;
  }

  while(!q.empty()) {
    g = q.front(); q.pop();
    if(pushToQ_And_CheckIsOver(g)) {
      cout << 1;
      return 0;
    }
  }

  cout << 0;
}