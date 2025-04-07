#include <iostream>
#include <climits>

using namespace std;
using ll = long long;

int n, d, a[100'001];
ll segmentTree[262'143], dp[100'001], ans = LLONG_MIN;

void updateSegmentTree(int node, int s, int e, int idx, ll v) {
  if(idx < s || idx > e) return;

  // 리프노드일 때
  if(s == e) {
    segmentTree[node] = v;
    return;
  }

  int m = (s + e) / 2;
  updateSegmentTree(2 * node, s, m, idx, v);
  updateSegmentTree(2 * node + 1, m+1, e, idx, v);
  // 자식 노드를 만들고 자식 노드의 값을 가져와서 현재의 노드를 업데이트 -> 이 작업을 재귀적으로
  segmentTree[node] = max(segmentTree[node * 2], segmentTree[node * 2 + 1]);
}

ll findFromSegmentTree(int node, int s, int e, int cs, int ce) {
  // 트리 범위와 부분집합이 없는 커버리지
  if(s > ce || e < cs) return LLONG_MIN;
  // 트리 범위의 부분집합인 커버리지
  if(cs <= s && e <= ce) return segmentTree[node];

  // 트리 범위와 교집합이 있는 커버리지
  int m = (s + e) / 2;
  return max(
    findFromSegmentTree(2 * node, s, m, cs, ce),
    findFromSegmentTree(2 * node + 1, m + 1, e, cs, ce)
  );
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d;
  for(int i = 1; i <= n; i++) cin >> a[i];

  ans = a[1];
  updateSegmentTree(1, 1, n, 1, a[1]);
  
  for(int i = 2; i <= n; i++) {
    ll tmp = max(0LL, findFromSegmentTree(1, 1, n, max(1, i-d), i-1));
    ans = max(ans, a[i] + tmp);
    updateSegmentTree(1, 1, n, i, a[i] + tmp);
  }

  cout << ans;
}