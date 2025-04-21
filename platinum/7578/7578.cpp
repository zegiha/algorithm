#include <iostream>
#include <vector>
#include <cmath>

#define MAX 500001

using namespace std;
using ll = long long;

int n, a[500'001], b[1'000'001];
ll ans = 0;
bool check[500'001];
vector <ll> st;

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int th = (int)ceil(log2(MAX));
  st.resize(1 << (th + 1), 0);
}

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    int t; cin >> t;
    b[t] = i;
  }
}

void ust(int n, int s, int e, int i, ll v) {
  if(e < i || i < s) return;

  st[n] += v;
  if(s == e) return;

  int m = (s + e) / 2;
  ust(n * 2, s, m, i, v);
  ust(n * 2 + 1, m + 1, e, i, v);
}

ll qst(int n, int s, int e, int qs, int qe) {
  // 교집합 없음
  if(e < qs || qe < s) return 0;
  // 부분집합임
  if(qs <= s && e <= qe) return st[n];
  
  int m = (s + e) / 2;
  return qst(n * 2, s, m, qs, qe) + qst(n * 2 + 1, m + 1, e, qs, qe);
}

int main() {
  init();
  input();
  for(int i = 1; i <= n; i++) {
    int bIdx = b[a[i]];
    ans += qst(1, 1, n, bIdx + 1, n);
    ust(1, 1, n, bIdx, 1);
  }
  
  cout << ans;
}