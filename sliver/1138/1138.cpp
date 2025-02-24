#include <iostream>
#include <vector>

using namespace std;

int arr[11], n;

bool visit[12] = {0, };
void solve(int d, vector <int> res) {
  if(d == n) {
    bool sw = true;
    for(int i = 0; i < n; i++) {
      int visible = 0;
      for(int j = 0; j < i; j++) if(res[i] < res[j]) visible++;
      // cout << res[i] << ' ' << i << ' ' << visible << '\n';
      if(arr[res[i]] != visible) {
        sw = false;
        break;
      }
    }
    if(sw) {
      for(int i = 0; i < n; i++) cout << res[i] + 1 << ' ';
    }
    return;
  }

  for(int i = 0; i < n; i++) {
    if(!visit[i]) {
      visit[i] = true;
      res.push_back(i);
      solve(d + 1, res);
      res.pop_back();
      visit[i] = false;
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  solve(0, vector <int> (0));
}