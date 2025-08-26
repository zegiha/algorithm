#include <iostream>
#include <stdio.h>

using namespace std;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int n, arr[20][20], ans;

int check[5];
void solve(int checkIdx) {
  if(checkIdx == 5) {
    int t[20][20] = {0, };

    // const int pattern[] = {2, 1, 3, 1, 3};
    // bool sw = true;
    // for(int i = 0; i < 5 && sw; i++) if(check[i] != pattern[i]) sw = false;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) t[i][j] = arr[i][j];

    for(int i = 0; i < 5; i++) {
      bool change[20][20] = {0, };
      switch(check[i]) {
        case 0: {
          for(int i = 0; i < n; i++) {
            for(int j = n-2; j >= 0; j--) {
              if(t[i][j] == 0) continue;
              
              int space = 0;
              while(t[i][j + (1 + space)] == 0 && j + (1 + space) < n) space++;

              if(
                j + 1 + space < n &&
                t[i][j] == t[i][j + 1 + space] &&
                !change[i][j] &&
                !change[i][j + 1 + space]
              ) {
                t[i][j + 1 + space] *= 2;
                t[i][j] = 0;
                change[i][j + (1 + space)] = true;
              } else {
                t[i][j + space] = t[i][j];
                if(j + space != j) t[i][j] = 0;
              }
            }
          }

          break;
        }
        case 1: {
          for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
              if(t[i][j] == 0) continue;

              int space = 0;
              while(t[i][j - (1 + space)] == 0 && j - (1 + space) >= 0) space++;

              if(
                j - (1 + space) > -1 &&
                t[i][j] == t[i][j - (1 + space)] &&
                !change[i][j] &&
                !change[i][j - (1 + space)]
              ) {
                t[i][j - (1 + space)] *= 2;
                t[i][j] = 0;
                change[i][j - (1 + space)] = true;
              } else {
                t[i][j - space] = t[i][j];
                if(j - space != j) t[i][j] = 0;
              }
            }
          }

          break;
        }
        case 2: {
          for(int j = 0; j < n; j++) {
            for(int i = n - 2; i >= 0; i--) {
              if(t[i][j] == 0) continue;
              
              int space = 0;
              while(t[i + (1 + space)][j] == 0 && i + (1 + space) < n) space++;
              if(
                i + (1 + space) < n &&
                t[i][j] == t[i + (1 + space)][j] &&
                !change[i][j] &&
                !change[i + (1 + space)][j]
              ) {
                t[i + (1 + space)][j] *= 2;
                t[i][j] = 0;
                change[i + 1 + space][j] = true;
              } else {
                t[i + space][j] = t[i][j];
                if(i + space != i) t[i][j] = 0;
              }
            }
          }

          break;
        }
        case 3: {
          for(int j = 0; j < n; j++) {
            for(int i = 1; i < n; i++) {
              if(t[i][j] == 0) continue;
              
              int space = 0;
              while(t[i - (1 + space)][j] == 0 && i - (1 + space) >= 0) space++;

              if(
                i - (1 + space) > -1 &&
                t[i][j] == t[i - (1 + space)][j] &&
                !change[i][j] &&
                !change[i - (1 + space)][j]
              ) {
                t[i - (1 + space)][j] *= 2;
                t[i][j] = 0;
                change[i - (1 + space)][j] = true;
              } else {
                t[i - space][j] = t[i][j];
                if(i - space != i) t[i][j] = 0;
              }
            }
          }

          break;
        }
      }

      // if(sw) {
        // cout << "\n========= " << i << " =========\n";
        // for(int i = 0; i < n; i++) {
        //   for(int j = 0; j < n; j++) cout << t[i][j] << ' ';
        //   cout << '\n';
        // }

        // cout << "\n===================\n";
      // }
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, t[i][j]);

    return;
  }

  for(int i = 0; i < 4; i++) {
    check[checkIdx] = i;
    solve(checkIdx + 1);
    check[checkIdx] = -1;
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
      ans = max(arr[i][j], ans);
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     printf("%4d ", arr[i][j]);
  //   }
  //   cout << '\n';
  // }

  solve(0);

  cout << ans;
}