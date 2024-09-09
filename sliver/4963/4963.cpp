#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w, h, arr[50][50], dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool visit[50][50];

bool isArea(int r, int c) {
  return r >= 0 && r < w && c >= 0 && c < h;
}

void bfs(int stR, int stC) {
  queue <pair <int, int>> q;
  visit[stR][stC] = true;
  q.push({stR, stC});
  while(!q.empty()) {
    pair<int, int> h = q.front();
    q.pop();
    for(int d = 0; d < 8; d++) {
      int newR = h.first + dy[d], newC = h.second + dx[d];
      if(isArea(newR, newC) && !visit[newR][newC] && arr[newR][newC] == 1) {
        visit[newR][newC] = true;
        q.push({newR, newC});
      }
    }
  }
}

int getAns() {
  int ans = 0;
  for(int i = 0; i < w; i++) {
    for(int j = 0; j < h; j++) {
      if(arr[i][j] == 1 && !visit[i][j]) {
        bfs(i, j);
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while(true) {
    cin >> h >> w;
    if(w == 0) return 0;
    for(int i = 0; i < w; i++) {
      for(int j = 0; j < h; j++) {
        cin >> arr[i][j];
      }
    }
    cout << getAns() << '\n';
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        visit[i][j] = false;
        arr[i][j] = 0;
      }
    }
  } 
}