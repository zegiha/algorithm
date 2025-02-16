#include <iostream>
#include <algorithm>

using namespace std;
using pii = pair <int, int>;

int arr[129][129], n;

pii get_ans(int r, int c, int size) {
  bool sw = false;
  int v = arr[r][c];
  pii res = {0, 0};

  for(int i = r; i < r + size; i++) {
    for(int j = c; j < c + size; j++) {
      if(v != arr[i][j]) {
        sw = true;
        break;
      }
    }
  }

  if(sw) {
    for(int i = r; i < r + size; i += size / 2) {
      for(int j = c; j < c + size; j += size / 2) {
        pii t = get_ans(i, j, size / 2);
        res.first += t.first;
        res.second += t.second;
      }
    }
    return res;
  } else {
    if(v == 0) res.first++;
    else res.second++;
    return res;
  }

}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  pii ans = get_ans(0, 0, n);

  cout << ans.first << '\n' << ans.second;
}