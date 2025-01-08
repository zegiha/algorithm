#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tcdn {
  int direction;
  int row;
  int column;
};
using pipipii = pair <int, pair <int, pair <int, int>>>;

int w, h, arr[101][101], dist[101][101][4];
const int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
const char dirs[] = {'u', 'd', 'l', 'r'};
priority_queue <pipipii, vector<pipipii>, greater<pipipii>> q;

bool isArea(int row, int col) {
  return 0 <= row && row < h && 0 <= col && col < w;
}

tcdn get_move_cdn (tcdn cdn) {
  int nr = cdn.row + dy[cdn.direction], nc = cdn.column + dx[cdn.direction];
  if(isArea(nr, nc) && arr[nr][nc] != -1) {
    return {cdn.direction, nr, nc};
  }
  return {-1, -1, -1};
}

void push_to_q(tcdn cdn, int dist_v) {
  tcdn new_cdn = get_move_cdn(cdn);
  if(new_cdn.row != -1) {
      // cout << "asdads";
    if(dist[new_cdn.row][new_cdn.column][new_cdn.direction] == -1 || dist[new_cdn.row][new_cdn.column][new_cdn.direction] > dist_v) {
      q.push({dist_v, {new_cdn.direction, {new_cdn.row, new_cdn.column}}}); 
      dist[new_cdn.row][new_cdn.column][new_cdn.direction] = dist_v;
    }
  }

  int rotate_direction = 2;
  if(!(cdn.direction == 0 || cdn.direction == 1)) rotate_direction = 0;
  for(int i = 0; i < 2; i++) {
    tcdn new_cdn = get_move_cdn({rotate_direction + i, cdn.row, cdn.column});
    int new_dist_v = dist_v + 1;
    if(new_cdn.row != -1) {
      if(dist[new_cdn.row][new_cdn.column][new_cdn.direction] == -1 || dist[new_cdn.row][new_cdn.column][new_cdn.direction] > new_dist_v) {
        q.push({new_dist_v, {new_cdn.direction, {new_cdn.row, new_cdn.column}}});
        dist[new_cdn.row][new_cdn.column][new_cdn.direction] = new_dist_v;
      }
    }
  }
}

int main() {
  cin >> w >> h;

  pair <int, int> start, end;
  int ti = 1;
  char tc;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> tc;
      if(tc == '.') {
        arr[i][j] = 0;
      } else if(tc == '*') {
        arr[i][j] = -1;
      } else {
        if(ti == 1) start = {i, j};
        else end = {i, j};
        arr[i][j] = ti++;
      }
      for(int t = 0; t < 4; t++) dist[i][j][t] = -1;
    }
  }

  // cout << "===============\n";

  for(int i = 0; i < 4; i++) {
    q.push({0, {i, {start.first, start.second}}});
    dist[start.first][start.second][i] = 0;
  }

  // for(int i = 0; i < h; i++) {
  //   for(int j = 0; j < w; j++) {
  //     for(int k = 0; k < 4; k++) {
  //       cout << dist[i][j][k] << '|';
  //     }
  //     cout << "  ";
  //   }
  //   cout << '\n';
  // }

  while(!q.empty()) {
    int v = q.top().first;
    int d = q.top().second.first, r = q.top().second.second.first, c = q.top().second.second.second;
    q.pop();
    if(dist[r][c][d] != -1 && dist[r][c][d] < v) continue;

    push_to_q({d, r, c}, v);
  }

  int ans = 2'100'000'000;
  for(int i = 0; i < 4; i++) {
    if(dist[end.first][end.second][i] != -1) {
      ans = min(ans, dist[end.first][end.second][i]);
    }
  }

  // for(int i = 0; i < h; i++) {
  //   for(int j = 0; j < w; j++) {
  //     for(int k = 0; k < 4; k++) {
  //       cout << dist[i][j][k] << '|';
  //     }
  //     cout << "  ";
  //   }
  //   cout << '\n';
  // }

  // for(int i = 0; i < h; i++) {
  //   for(int j = 0; j < w; j++) {
  //     cout << arr[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  // cout << start.first << ' ' << start.second << '\n' << end.first << ' ' << end.second << endl;

  cout << ans;
}
