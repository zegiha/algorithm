#include <iostream>
#include <vector>

using namespace std;
using pii = pair <int, int>;
using vpii = vector <pii>;
using vi = vector <int>;
using vvi = vector <vi>;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int n, ans = 0, maxCheckCnt;

vvi arr;

vpii newCheck = {};
bool check[20][20];
vvi move(int d, vvi arr, int& checkCnt, int& maxCheckCnt) {
  // cout << "check3\n";
  switch(d) {
    case 0: {
      for(int i = 0; i < n; i++) {
        for(int j = n-2; j >= 0; j--) {
          // cout << "\n================\n" << i << ' ' << j << '\n';

          int t = j + 1;
          while(arr[i][t] == 0 && t < n-1) {
            t++;
          }
          if(arr[i][t] != 0 && arr[i][t] == arr[i][j] && !check[i][j] && check[i][t] == check[i][j]) {
            newCheck.push_back({i, t});
            check[i][t] = check[i][j] = true;
            maxCheckCnt--;
            checkCnt++;
            // cout << "case 1 : " << t << '\n';
            arr[i][t] *= 2;
            arr[i][j] = 0;
          } else if(arr[i][t] == 0) {
            // cout << "case 2 : " << t << '\n';
            arr[i][t] = arr[i][j];
            arr[i][j] = 0;
          } else if(t - 1 != j) {
            // cout << "case 3 : " << t << '\n';
            arr[i][t - 1] = arr[i][j];
            arr[i][j] = 0;
          }

          // cout << "============\n";
        }
      }
      break;
    }
    case 1: {
      for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
          // cout << "\n================\n" << i << ' ' << j << '\n';

          int t = j - 1;
          while(arr[i][t] == 0 && t > 0) {
            t--;
          }
          if(arr[i][t] != 0 && arr[i][t] == arr[i][j] && !check[i][j] && check[i][t] == check[i][j]) {
            newCheck.push_back({i, t});
            check[i][t] = check[i][j] = true;
            maxCheckCnt--;
            checkCnt++;
            // cout << "case 1 : " << t << '\n';
            arr[i][t] *= 2;
            arr[i][j] = 0;
          } else if(arr[i][t] == 0) {
            // cout << "case 2 : " << t << '\n';
            arr[i][t] = arr[i][j];
            arr[i][j] = 0;
          } else if(t + 1 != j) {
            // cout << "case 3 : " << t << '\n';
            arr[i][t + 1] = arr[i][j];
            arr[i][j] = 0;
          }

          // cout << "============\n";
        }
      }
      break;
    }
    case 2: {
      for(int j = 0; j < n; j++) {
        for(int i = n-2; i >= 0; i--) {
          // cout << "\n================\n" << i << ' ' << j << '\n';

          int t = i + 1;
          while(arr[t][j] == 0 && t < n-1) {
            t++;
          }
          if(arr[t][j] != 0 && arr[t][j] == arr[i][j] && !check[i][j] && check[t][j] == check[i][j]) {
            // cout << "case 1 : " << t << '\n';
            check[t][j] = check[i][j] = true;
            newCheck.push_back({t, j});
            maxCheckCnt--;
            checkCnt++;
            arr[t][j] *= 2;
            arr[i][j] = 0;
          } else if(arr[t][j] == 0) {
            // cout << "case 2 : " << t << '\n';
            arr[t][j] = arr[i][j];
            arr[i][j] = 0;
          } else if(t - 1 != i) {
            // cout << "case 3 : " << t << '\n';
            arr[t - 1][j] = arr[i][j];
            arr[i][j] = 0;
          }

          // cout << "============\n";
        }
      }
      break;
    }
    case 3: {
      for(int j = 0; j < n; j++) {
        for(int i = 1; i < n; i++) {
          // cout << "\n================\n" << i << ' ' << j << '\n';

          int t = i - 1;
          while(arr[t][j] == 0 && t > 0) {
            t--;
          }
          if(arr[t][j] != 0 && arr[t][j] == arr[i][j] && !check[i][j] && check[t][j] == check[i][j]) {
            check[t][j] = check[i][j] = true;
            newCheck.push_back({t, j});
            maxCheckCnt--;
            checkCnt++;
            // cout << "case 1 : " << t << '\n';
            arr[t][j] *= 2;
            arr[i][j] = 0;
          } else if(arr[t][j] == 0) {
            // cout << "case 2 : " << t << '\n';
            arr[t][j] = arr[i][j];
            arr[i][j] = 0;
          } else if(t + 1 != i) {
            // cout << "case 3 : " << t << '\n';
            arr[t + 1][j] = arr[i][j];
            arr[i][j] = 0;
          }

          // cout << "============\n";
        }
      }
      break;
    }
  }

  return arr;
}

void solve(int moveCnt, vvi map, int checkCnt, int maxCheckCnt) {
  // cout << "check1\n";
  if(moveCnt == 5 || checkCnt == maxCheckCnt) {
  // cout << "check4\n";
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans = max(ans, map[i][j]);

    return;
  }

  for(int d = 0; d < 4; d++) {
  // cout << "check2\n";
    int newCheckCnt = checkCnt, newMaxCheckCnt = maxCheckCnt;
    vvi newMap = move(d, map, newCheckCnt, newMaxCheckCnt);

    solve(moveCnt+1, newMap, newCheckCnt, newMaxCheckCnt);
  }
}

int main() {
  cin >> n;
  arr.resize(n + 1, vector <int> (n + 1));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      // cout << "check  " << i << " : " << j << '\n';
      cin >> arr[i][j];
      ans = max(ans, arr[i][j]);
      if(arr[i][j] != 0) maxCheckCnt++;
    }
  }

  solve(0, arr, 0, maxCheckCnt);

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     cout << arr[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << ans;
}