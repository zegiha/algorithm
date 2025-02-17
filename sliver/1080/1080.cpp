#include <iostream>

using namespace std;

int n, m, from[51][51], to[51][51], ans;

void change(int r, int c) {
  for(int i = r; i < r + 3; i++) {
    for(int j = c; j < c + 3; j++) {
      from[i][j] = !from[i][j];
    }
  }
}

bool is_same_haha() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(from[i][j] != to[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    for(int j = 0; j < m; j++) {
      from[i][j] = str[j] - '0';
    }
  }
  for(int i = 0; i < n; i++) {
    string str; cin >> str;
    for(int j = 0; j < m; j++) {
      to[i][j] = str[j] - '0';
    }
  }

  for(int i = 0; i < n - 2; i++) {
    for(int j = 0; j < m - 2; j++) {
      if(from[i][j] != to[i][j]) {
        change(i, j);
        ans++;
      }
    }
  }

  if(is_same_haha()) {
    cout << ans;
  } else {
    cout << -1;
  }
}