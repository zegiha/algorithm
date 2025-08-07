#include <iostream>
#include <vector>
#include <queue>

#define ROW_MAX 12
#define COL_MAX 6
#define RED 1
#define GREEN 2
#define BLUE 3
#define PUPLE 4
#define YELLOW 5


using namespace std;
using pii = pair <int, int>;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int arr[ROW_MAX][COL_MAX];

void input() {
  char input;
  for(int i = 0; i < ROW_MAX; i++) {
    for(int j = 0; j < COL_MAX; j++) {
      cin >> input;
      if(input == '.') {
        arr[i][j] = 0;
      } else {
        switch(input) {
          case 'R': {arr[i][j] = RED; break;}
          case 'G': {arr[i][j] = GREEN; break;}
          case 'B': {arr[i][j] = BLUE; break;}
          case 'P': {arr[i][j] = PUPLE; break;}
          case 'Y': {arr[i][j] = YELLOW; break;}
        }
      }
    }
  }
}

bool isArea(int r, int c) {
  return 0 <= r && r < ROW_MAX && 0 <= c && c < COL_MAX;
}

bool explodeAndGetIsExplode() {
  bool ans = false, visited[ROW_MAX][COL_MAX] = {0, };

  vector <pii> exp;
  for(int i = 0; i < ROW_MAX; i++) {
    for(int j = 0; j < COL_MAX; j++) {
      if(arr[i][j] && !visited[i][j]) {
        int nr, nc, r = i, c = j;
        const int color = arr[r][c];
        queue <pii> q;

        q.push({r, c});
        visited[r][c] = true;
        exp.push_back({r, c});

        while(!q.empty()) {
          r = q.front().first, c = q.front().second;
          q.pop();
          for(int d = 0; d < 4; d++) {
            nr = dy[d] + r, nc = dx[d] + c;
            if(isArea(nr, nc) && arr[nr][nc] == color && !visited[nr][nc]) {
              q.push({nr, nc});
              visited[nr][nc] = true;
              exp.push_back({nr, nc});
            }
          }
        }

        // for(auto t : exp) cout << "{ " << t.first << ", " << t.second << " }\n";
        // cout << i << ", " << j <<  " =================\n";

        if(exp.size() >= 4) {
          ans = true;
          for(pii t : exp) arr[t.first][t.second] = 0;
          }
        exp.clear();
      }
    }
  }
  return ans;
}

int main() {
  input();
  int ans = 0;
  vector <vector <pii>> groups;
  while(true) {
    // for(int i = 0; i < ROW_MAX; i++) {
    //   for(int j = 0; j < COL_MAX; j++) cout << arr[i][j] << ' ';
    //   cout << '\n';
    // }
    // cout << "====================================\n";

    if(!explodeAndGetIsExplode()) break;
    ans++;

    for(int j = 0; j < COL_MAX; j++) {
      for(int i = ROW_MAX - 1; i >= 0; i--) {
        if(!arr[i][j]) continue;
        int newI = i + 1;
        while(newI < ROW_MAX) {
          if(arr[newI][j]) break;
          newI++;
        }
        int t = arr[i][j];
        arr[i][j] = 0;
        arr[newI - 1][j] = t;
      }
    }
  }

  // for(int i = 0; i < ROW_MAX; i++) {
  //   for(int j = 0; j < COL_MAX; j++) cout << arr[i][j] << ' ';
  //   cout << '\n';
  // }
  // cout << "====================================\n";

  cout << ans;
}