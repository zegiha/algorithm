#include <iostream>
#include <vector>

using namespace std;

int bingo[5][5], say[5][5], check[5][5];

void sayAndCheck(int sayN) {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(bingo[i][j] == sayN) {
        check[i][j] = 1;
        break;
      }
    }
  }
}

int getLine() {
  int res = 0;
  for(int i = 0; i < 5; i++) {
    int cnt = 0;
    for(int j = 0; j < 5; j++) {
      cnt += check[i][j];
    }
    if(cnt == 5) res++;
  }
  for(int i = 0; i < 5; i++) {
    int cnt = 0;
    for(int j = 0; j < 5; j++) {
      cnt += check[j][i];
    }
    if(cnt == 5) res++;
  }

  int cnt = 0;
  for(int i = 0; i < 5; i++) {
    cnt += check[i][i];
  }
  if(cnt == 5) res++;

  cnt = 0;
  for(int i = 0; i < 5; i++) {
    cnt += check[i][4 - i];
  }
  if(cnt == 5) res++;

  return res;
}

int main() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> bingo[i][j];
    }
  }
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> say[i][j];
    }
  }

  int cnt = 0, ans = 0;;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      ans++;
      sayAndCheck(say[i][j]);
      cnt = getLine();
      if(cnt >= 3) {
        cout << ans;
        return 0;
      }
    }
  }
}