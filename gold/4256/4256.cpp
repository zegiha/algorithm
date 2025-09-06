#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> pre, in, parent;
vector <pair <int, int>> child;

void printAns(int v) {
  if(child[v].first != -1) printAns(child[v].first);
  if(child[v].second != -1) printAns(child[v].second);

  cout << v << ' ';
}

void solve() {
  pre.clear();
  in.clear();
  child.clear();
  parent.clear();

  cin >> n;

  pre.resize(n + 1);
  in.resize(n + 1);
  child.resize(n + 1, {-1, -1});
  parent.resize(n + 1, -1);

  for(int i = 0; i < n; i++) cin >> pre[i];
  for(int i = 0; i < n; i++) cin >> in[i];

  parent[pre[0]] = 0;
  child[pre[0]] = {-1, -1};

  for(int i = 1; i < n; i++) {
    int preIdx = i, inIdx, lc = -1, rc = -1;

    while(lc == -1 && rc == -1) {
      preIdx--;

      for(int i = 0; i < n; i++) if(pre[preIdx] == in[i]) {
        inIdx = i;
        break;
      }

      int t = inIdx - 1;

      // cout << inIdx << '\n';

      while(lc == -1 && 0 <= t && parent[in[t]] == -1) {
        // cout << in[t] << ' ' << pre[i] << '\n';
        if(in[t] == pre[i]) {
          lc = t;
          parent[pre[i]] = in[inIdx];
          child[in[inIdx]].first = pre[i];
          break;
        }
        t--;
      }

      if(lc != -1) break;

      t = inIdx + 1;

      while(rc == -1 && t < n && parent[in[t]] == -1) {
        if(in[t] == pre[i]) {
          rc = t;
          parent[pre[i]] = in[inIdx];
          child[in[inIdx]].second = pre[i];
        }
        t++;
      }

      if(rc != -1) break;
    }

    // cout << pre[i] << "'s parent is " << parent[pre[i]] << '\n';
  }

  printAns(pre[0]);
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
    cout << '\n';
  }
}