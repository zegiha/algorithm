#include <iostream>
#include <cmath>
#include <vector>

#define MAX 1000000

using namespace std;
using ll = long long;

vector <ll> st;

int querySt(int node, int start, int end, int cnt) {
  if(start == end) return start;

  int mid = (start + end) / 2;
  if(st[node * 2] >= cnt) return querySt(node * 2, start, mid, cnt);
  else return querySt(node * 2 + 1, mid + 1, end, cnt - st[node * 2]);
}

void updateSt(int node, int start, int end, int idx, int value) {
  if(idx < start || idx > end) return;
  st[node] += (ll)value;

  if(start != end) {
    int mid = (start + end) / 2;
    updateSt(node * 2, start, mid, idx, value);
    updateSt(node * 2 + 1, mid + 1, end, idx, value);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int treeHeight = (int)ceil(log2(MAX));
  int treeSize = 1 << (treeHeight + 1);
  st.resize(treeSize);

  int t, a, b, c; cin >> t;
  while(t--) {
    cin >> a >> b;
    if(a == 1) {
      int res = querySt(1, 1, MAX, b);
      cout << res << '\n';
      updateSt(1, 1, MAX, res, -1);
    } else {
      cin >> c;
      updateSt(1, 1, MAX, b, c);
    }
  }
}