#include <iostream>
#include <queue>

using namespace std;

using pipii = pair <int, pair <int, int>>;

int pow(int n) {
  return n * n;
}

int abs(int n) {
  return n < 0 ? n * -1 : n;
}

int n, m, t, d, arr[26][26], dist1[26][26], dist2[26][26];

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool isArea(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
  cin >> n >> m >> t >> d;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      if('a' <= c) {
        arr[i][j] = c - 'a' + 26;
      } else {
        arr[i][j] = c - 'A';
      }
      dist1[i][j] = -1;
      dist2[i][j] = -1;
    }
  }

  priority_queue <pipii, vector<pipii>, greater<pipii>> q;

  q.push({0, {0, 0}});
  dist1[0][0] = 0;

  while(!q.empty()) {
    int r = q.top().second.first, c = q.top().second.second, current_time = q.top().first;
    q.pop();

    if(dist1[r][c] != -1 && dist1[r][c] < current_time) continue;

    for(int dir = 0; dir < 4; dir++) {
      int newR = r + dy[dir], newC = c + dx[dir];
      if(isArea(newR, newC)) {
        int current_height = arr[r][c], new_height = arr[newR][newC], new_time=-1;

        if(abs(new_height - current_height) <= t) {
          if(current_height < new_height) {
            new_time = current_time + pow(new_height - current_height);
          } else {
            new_time = current_time + 1;
          }
          if(dist1[newR][newC] == -1 || dist1[newR][newC] > new_time) {
            q.push({new_time, {newR, newC}});
            dist1[newR][newC] = new_time;
          }
        }
      }
    }
  }

  q.push({0, {0, 0}});
  dist2[0][0] = 0;

  while(!q.empty()) {
    int r = q.top().second.first, c = q.top().second.second, current_time = q.top().first;
    q.pop();

    if(dist2[r][c] != -1 && dist2[r][c] < current_time) continue;

    for(int dir = 0; dir < 4; dir++) {
      int newR = r + dy[dir], newC = c + dx[dir];
      if(isArea(newR, newC)) {
        int current_height = arr[r][c], new_height = arr[newR][newC], new_time=-1;

        if(abs(new_height - current_height) <= t) {
          if(current_height > new_height) {
            new_time = current_time + pow(new_height - current_height);
          } else {
            new_time = current_time + 1;
          }
          if(dist2[newR][newC] == -1 || dist2[newR][newC] > new_time) {
            q.push({new_time, {newR, newC}});
            dist2[newR][newC] = new_time;
          }
        }
      }
    }
  }

  int ans = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(dist1[i][j] == -1) continue;
      int newTime = dist1[i][j] + dist2[i][j];
      if(newTime <= d && arr[i][j] > ans) {
        ans = arr[i][j];
      }
    }
  }

  cout << ans;
}