#include <iostream>

using namespace std;

int n, m, k, arr[16][16], arr2[16][16];

int get_dp_1(int r, int c) {
  if(arr[r][c] != -1) {
    return arr[r][c];
  }

  int a = 0, b = 0;
  if(r - 1 >= 0) {
    a = get_dp_1(r - 1, c);
  }
  if(c - 1 >= 0) {
    b = get_dp_1(r, c - 1);
  }

  arr[r][c] = a + b;
  return a + b;
}

int get_dp_2(int r, int c) {
  if(arr2[r][c] != -1) {
    return arr2[r][c];
  }

  int a = 0, b = 0;
  if(r - 1 >= 0) {
    a = get_dp_2(r - 1, c);
  }
  if(c - 1 >= 0) {
    b = get_dp_2(r, c - 1);
  }

  arr2[r][c] = a + b;
  return a + b;
}

int main() {
  cin >> n >> m >> k; k--;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      arr[i][j] = -1;
      arr2[i][j] = -1;
    }
  }
  arr[0][0] = 1;

  if(k != -1) {
    arr2[k / m][k % m] = 1;
    int a = get_dp_1(k / m, k % m);
    int b = get_dp_2(n - 1, m - 1);
    cout << a * b;
  } else {
    int a = get_dp_1(n - 1, m - 1);
    cout << a;
  }
}