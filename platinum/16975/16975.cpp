#include <iostream>

#define MAX 100000

using namespace std;
using ll = long long;

ll
tree[MAX * 4 + 100] = {0, },
lazy[MAX * 4 + 100] = {0, };

int a[MAX + 1], n;

void ist(int n, int s, int e) {
  if(s == e) {
    tree[n] = a[s];
    return;
  }

  int m = (s + e) / 2;
  ist(n * 2, s, m);
  ist(n * 2 + 1, m + 1, e);
  tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

void propagation(int n, int s, int e) {
  if(lazy[n] == 0) return;
  tree[n] += lazy[n] * (e - s + 1);
  if(s != e) {
    lazy[n * 2] += lazy[n];
    lazy[n * 2 + 1] += lazy[n];
  }
  lazy[n] = 0;
}

void ust(int n, int s, int e, int us, int ue, int v) {
  propagation(n, s, e);
  if(ue < s || e < us) return;
  if(us <= s && e <= ue) {
    lazy[n] += v;
    propagation(n, s, e);
    return;
  }

  int m = (s + e) / 2;
  ust(n * 2, s, m, us, ue, v);
  ust(n * 2 + 1, m + 1, e, us, ue, v);
  tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

ll qst(int n, int s, int e, int i) {
  propagation(n, s, e);
  if(i < s || e < i) return 0;
  if(i <= s && e <= i) return tree[n];

  int m = (s + e) / 2;
  return qst(n * 2, s, m, i) + qst(n * 2 + 1, m + 1, e, i);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  ist(1, 1, n);

  int m, a, b, c, d; cin >> m;
  while(m--) {
    cin >> a >> b;
    if(a == 1) {
      cin >> c >> d;
      ust(1, 1, n, b, c, d);
    } else {
      cout << qst(1, 1, n, b) << '\n';
    }
  }
}