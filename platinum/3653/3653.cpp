#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> tree, arr;

void update(int n, int s, int e, int i, int v) {
  if(i < s || e < i) return;
  tree[n] += v;

  if(s == e) return;
  int m = (s + e) / 2;
  update(n * 2, s, m, i, v);
  update(n * 2 + 1, m + 1, e, i, v);
}

int query(int n, int s, int e, int qs, int qe) {
  if(qe < s || e < qs) return 0;
  if(qs <= s && e <= qe) return tree[n];

  int m = (s + e) / 2;
  return query(n * 2, s, m, qs, qe) + query(n * 2 + 1, m + 1, e, qs, qe);
}

void solve() {
  cin >> n >> m;
  tree.clear(); tree.resize(4 * (n + m + 10));
  arr.clear(); arr.resize(n + m + 10);

  for(int i = m + 1; i <= n + m; i++) {
    update(1, 1, n + m, i, 1);
    arr[i-m] = i;
  }

  int idx = m, t;
  for(int tmp = 0; tmp < m; tmp++) {
    cin >> t;
    cout << query(1, 1, n + m, 1, arr[t] - 1) << ' ';
    update(1, 1, n + m, arr[t], -1);
    arr[t] = idx--;
    update(1, 1, n + m, arr[t], 1);
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  while(t--) {
    solve();
    cout << '\n';
  }
}