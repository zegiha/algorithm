#include <iostream>
#include <queue>

using namespace std;

const int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
int max_row, max_col, n, arr[201][201];

void step() {
  for(int i = 0; i < max_row; i++) {
    for(int j = 0; j < max_col; j++) {
      if(arr[i][j] != -1) {
        arr[i][j]++;
      }
    }
  }
}

void add_bomb() {
  for(int i = 0; i < max_row; i++) {
    for(int j = 0; j < max_col; j++) {
      if(arr[i][j] == -1) {
        arr[i][j] = 0;
      }
    }
  }
}

bool isArea(int r, int c) {
  return 0 <= r && r < max_row && 0 <= c && c < max_col;
}
void bomb() {
  queue <pair <int, int>> q;
  int visit[201][201] = {0,};
  for(int i = 0; i < max_row; i++) {
    for(int j = 0; j < max_col; j++) {
      if(arr[i][j] == 3) {
        q.push({i, j});
        visit[i][j] = true;
        arr[i][j] = -1;
        while(!q.empty()) {
          int r = q.front().first, c = q.front().second;
          q.pop();
          for(int d = 0; d < 4; d++) {
            int nr = r + dy[d], nc = c + dx[d];
            if(isArea(nr, nc)) {
              if(!visit[nr][nc] && arr[nr][nc] == 3) {
                q.push({nr, nc});
              }
              visit[nr][nc] = true;
              arr[nr][nc] = -1;
            }
          }
        }
      }
    }
  }
}

void painting(bool isEnter, bool isNumber) {
  for(int i = 0; i < max_row; i++) {
    for(int j = 0; j < max_col; j++) {
      if(isNumber) {
        if(arr[i][j] == -1) cout << 'X';
        else cout << arr[i][j];
      }
      else {
        if(arr[i][j] == -1) cout << '.';
        else cout << 'O';
      }
    }
    cout << '\n';
  }
  if(isEnter) cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> max_row >> max_col >> n;
  for(int i = 0; i < max_row; i++) {
    for(int j = 0; j < max_col; j++) {
      char c; cin >> c;
      if(c == '.') {
        arr[i][j] = -1;
      } else {
        arr[i][j] = 0;
      }
    }
  }

  n--;
  step();

  bool sw = true;
  while(n--) {
    step();
    // painting(true, true);
    if(sw) {
      add_bomb();
      // painting(true, true);
    }
    bomb();
    // painting(true, true);
    // cout << "=======================================\n";
  }

  painting(false, false);
}