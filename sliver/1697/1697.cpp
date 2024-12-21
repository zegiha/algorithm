#include <iostream>
#include <queue>

using namespace std;

int n, m;

int ans = 1;
bool visit[100'001] = {0,};
queue <int> q;

const int dx[] = {-1, 1};

bool isArea(int pos) {
  return 0 <= pos && pos <= 100'000;
}

bool ans_pipe(int new_pos) {
  if(isArea(new_pos) && !visit[new_pos]) {
    q.push(new_pos);
    visit[new_pos] = true;
    if(new_pos == m) {
      cout << ans;
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> m;

  if(n == m) {
    cout << 0;
    return 0;
  }

  q.push(n);
  visit[n] = true;

  while(!q.empty()) {
    int size = q.size();
    while(size--) {
      int pos = q.front(), new_pos;
      q.pop();

      for(int d = 0; d < 2; d++) {
        new_pos = pos + dx[d];
        if(ans_pipe(new_pos)) return 0;
      }

      new_pos = pos * 2;
      if(ans_pipe(new_pos)) return 0;
    }
    ans++;
  }
}