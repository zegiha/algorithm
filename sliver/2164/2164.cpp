#include <iostream>
#include <queue>

using namespace std;

int n, ans;
queue <int> q;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) q.push(i);
  int t = 1;
  while(!q.empty()) {
    ans = q.front();
    if(t % 2 == 0) {
      q.push(q.front());
      q.pop();
    } else q.pop();
    t++;
  }

  cout << ans;
}