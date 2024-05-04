#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, ans;
int arr[10002][10002];

void dfs(int root) {
  stack <pair <int, int>> s;
  bool visit[10002] = {0, };
  s.push(make_pair(root, 0));
  visit[root] = true;
  while(!s.empty()) {
    bool sw = true;
    int i = s.top().first, sum = s.top().second;
    s.pop();
    // cout << i << "  ||  i\n" << sum << "  ||  sum\n";
    for(int j = 1; j <= n; j++) {
      if(arr[i][j] != 0 && !visit[j]) {
        visit[j] = true;
        s.push(make_pair(j, sum + arr[i][j]));
        sw = false;
      }
    }
    if(sw) {
      // cout << "end\n\n";
      if(ans < sum) ans = sum;
    }
  }
}

int main() {
  cin >> n;
  // arr.resize(n + 2, vector <int> (n + 2, 0));
  for(int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a][b] = c;
    arr[b][a] = c;
  }

  for(int i = 1; i <= n; i++) {
    dfs(i);
  }
  cout << ans;
}