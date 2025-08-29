#include <iostream>
#include <queue>

#define RED 1
#define BLUE 2
#define EXIT 9

using namespace std;
using pii = pair <int, int>;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int n, m, arr[11][11];

pair <bool, bool> moveAndCheckIsEnd(pii& red, pii& blue, int d) {
  bool isRedFell = false, isBlueFell = false;

  switch(d) {
    case 0: {
      for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
          if(red.first == i && red.second == j) {
            int t = j;
            while(
              !(arr[i][t - 1] == -1 ||
              (!isBlueFell && blue.first == i && blue.second == t-1))
            ) {
              t--;
              if(arr[i][t] == EXIT) {
                isRedFell = true;
                break;
              }
            }
            red = {i, t};
          } else if(blue.first == i && blue.second == j) {
             int t = j;
            while(
              !(arr[i][t - 1] == -1 ||
              (!isRedFell && red.first == i && red.second == t-1))
            ) {
              t--;
              if(arr[i][t] == EXIT) {
                isBlueFell = true;
                break;
              }
            }
            blue = {i, t};           
          }
        }
      }

      break;
    }

    case 1: {
      for(int i = 0; i < n; i++) {
        for(int j = m-2; j >= 0; j--) {
          if(red.first == i && red.second == j) {
            int t = j;
            while(
              !(arr[i][t + 1] == -1 ||
              (!isBlueFell && blue.first == i && blue.second == t+1))
            ) {
              t++;
              if(arr[i][t] == EXIT) {
                isRedFell = true;
                break;
              }
            }
            red = {i, t};
          } else if(blue.first == i && blue.second == j) {
             int t = j;
            while(
              !(arr[i][t + 1] == -1 ||
              (!isRedFell && red.first == i && red.second == t+1))
            ) {
              t++;
              if(arr[i][t] == EXIT) {
                isBlueFell = true;
                break;
              }
            }
            blue = {i, t};           
          }
        }
      }

      break;
    }

    case 2: {
      for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
          if(red.first == j && red.second == i) {
            int t = j;
            while(
              !(arr[t-1][i] == -1 ||
              (!isBlueFell && blue.first == t-1 && blue.second == i))
            ) {
              t--;
              if(arr[t][i] == EXIT) {
                isRedFell = true;
                break;
              }
            }
            red = {t, i};
          } else if(blue.first == j && blue.second == i) {
             int t = j;
            while(
              !(arr[t-1][i] == -1 ||
              (!isRedFell && red.first == t-1 && red.second == i))
            ) {
              t--;
              if(arr[t][i] == EXIT) {
                isBlueFell = true;
                break;
              }
            }
            blue = {t, i};
          }
        }
      }

      break;
    }

    case 3: {
      for(int i = 0; i < m; i++) {
        for(int j = n-2; j >= 0; j--) {
          if(red.first == j && red.second == i) {
            int t = j;
            while(
              !(arr[t+1][i] == -1 ||
              (!isBlueFell && blue.first == t+1 && blue.second == i))
            ) {
              t++;
              if(arr[t][i] == EXIT) {
                isRedFell = true;
                break;
              }
            }
            red = {t, i};
          } else if(blue.first == j && blue.second == i) {
             int t = j;
            while(
              !(arr[t+1][i] == -1 ||
              (!isRedFell && red.first == t+1 && red.second == i))
            ) {
              t++;
              if(arr[t][i] == EXIT) {
                isBlueFell = true;
                break;
              }
            }
            blue = {t, i};
          }
        }
      }
    }
  }

  return {isRedFell, isBlueFell};
}

int main() {
  pii red, blue;

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string t; cin >> t;
    for(int j = 0; j < m; j++) {
      switch(t[j]) {
        case '#': arr[i][j] = -1; break;
        case '.': arr[i][j] = 0; break;
        case 'R': {
          red = {i, j};
          arr[i][j] = 0; break;
        }
        case 'B': {
          blue = {i, j};
          arr[i][j] = 0; break;
        }
        case 'O': arr[i][j] = EXIT; break;
      }
    }
  }

  int ans = 0;
  queue <pair <pii, pii>> q;
  bool v[11][11][11][11] = {0, }, sw = false;

  q.push({red, blue});
  v[red.first][red.second][blue.first][blue.second] = true;

  while(!q.empty() && !sw) {
    // cout << "\n\n===============================\n\n";
    int size = q.size();
    while(size-- && !sw) {
      pii red = q.front().first, blue = q.front().second;
      q.pop();

      for(int d = 0; d < 4; d++) {
        pii nRed = red, nBlue = blue;
        pair <bool, bool> t = moveAndCheckIsEnd(nRed, nBlue, d);
        // cout << nRed.first << ' ' << nRed.second <<  ' ' << nBlue.first <<  ' ' << nBlue.second << ' ' << t.first << ' ' << t.second << '\n';

        bool isRedFell = t.first, isBlueFell = t.second;
        if(
          !isRedFell &&
          !isBlueFell &&
          !v[nRed.first][nRed.second][nBlue.first][nBlue.second]
        ) {
          q.push({nRed, nBlue});
          v[nRed.first][nRed.second][nBlue.first][nBlue.second] = true;
        } else {
          if(isRedFell && !isBlueFell) {
            sw = true;
          }
        }
      }
    }
    // cout << "\n\n===============================\n\n";
    ans++;
  }

  if(!sw) cout << -1;
  else cout << ans;
}