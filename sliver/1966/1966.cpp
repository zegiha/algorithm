#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector <int> arr;

bool isBig(pair <int, int> f) {
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] > f.first) return false;
  }
  return true;
}

void solve() {
  int ans = 0;
  cin >> n >> m;
  
  arr.resize(n);
  queue <pair <int, int>> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];  
    q.push({arr[i], i});
  }
  while(!q.empty()) {
    pair <int, int> f = q.front();
    if(isBig(f)) {
      ans++;
      arr[f.second] = -1;
      if(f.second == m) {
        cout << ans << '\n';
        break;
      }
    } else {
      q.push(f);
    }
    q.pop();
  }

  arr.clear();
  return;
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}