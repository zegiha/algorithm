#include <iostream>

using namespace std;

int n, k, arr[9], ans;

bool visit[8] = {0, };
void solve(int sum, int depth) {
  if(depth == n) {
    ans++;
    return;
  }

  for(int i = 0; i < n; i++) {
    if(!visit[i] && sum + arr[i] - k >= 0) {
      visit[i] = true;
      solve(sum + arr[i] - k, depth + 1);
      visit[i] = false;
    }
  }
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> arr[i];

  solve(0, 0);

  cout << ans;
}