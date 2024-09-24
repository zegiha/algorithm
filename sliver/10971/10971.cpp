#include <iostream>

using namespace std;

int n, arr[10][10], ans = 2'100'000'000;
bool visit[10] = {0, };

void backtrack(int depth, int last, int cnt, int root) {
  if(depth == n) {
    if(arr[last][root] != 0) {
      cnt += arr[last][root];
      if(cnt < ans) ans = cnt;
    }
    return;
  }
  for(int i = 0; i < n; i++) {
    if(!visit[i] && arr[last][i] != 0) {
      visit[i] = true;
      backtrack(depth + 1, i, cnt + arr[last][i], root);
      visit[i] = false;
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];

  for(int i = 0; i < n; i++) {
    visit[i] = true;
    backtrack(1, i, 0, i);
    visit[i] = false;
  }

  cout << ans;  
}