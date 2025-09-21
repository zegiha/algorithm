#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector <int> arr[200'001];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    arr[a].push_back(b);
  }

  int ans = 0;
  priority_queue <int, vector <int>, less<int>> q;
  for(int i = n; i >= 1; i--) {
    for(int j = 0; j < arr[i].size(); j++) {
      q.push(arr[i][j]);
    }

    if(!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }

  cout << ans;
}
