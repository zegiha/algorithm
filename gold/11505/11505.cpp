#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;
using ll = long long;

vector<ll> tree;
int n, arr[1'000'000], m, k, treeHeight;

bool isArea(int start, int end, int target) {
  return start <= target && target <= end;
}

ll makeTree(int node, int start, int end) {
  if(start == end) return tree[node] = (ll)arr[start];

  int mid = (start + end) / 2;

  ll
  left = makeTree(node * 2, start, mid),
  right = makeTree(node * 2 + 1, mid + 1, end);

  return tree[node] = (left * right) % MOD;
}

ll changeNode(int node, int start, int end, int target) {
  if(!(start <= target && target <= end)) return tree[node];

  if(start == end) return tree[node] = (ll)arr[start];

  int mid = (start + end) / 2;

  ll
  left = changeNode(node * 2, start, mid, target),
  right = changeNode(node * 2 + 1, mid + 1, end, target);

  return tree[node] = (left * right) % MOD;
}

ll getSegment(int node, int start, int end, int startSegment, int endSegment) {
  bool
  isSEAreaInSegmentS = isArea(start, end, startSegment),
  isSEAreaInSegmentE = isArea(start, end, endSegment),
  isSegmentSEAreaInS = isArea(startSegment, endSegment, start),
  isSegmentSEAreaInE = isArea(startSegment, endSegment, end);

  if(
    !isSEAreaInSegmentS &&
    !isSEAreaInSegmentE &&
    !isSegmentSEAreaInS &&
    !isSegmentSEAreaInE
  ) return 1;

  if(
    isSegmentSEAreaInS &&
    isSegmentSEAreaInE
  ) return tree[node];

  int mid = (start + end) / 2;
  return (
    getSegment(node * 2, start, mid, startSegment, endSegment) *
    getSegment(node * 2 + 1, mid + 1, end, startSegment, endSegment)
  ) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;

  treeHeight = ceil(log2(n));
  tree.resize(1 << (treeHeight + 1));

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  makeTree(1, 0, n-1);

  int loop = k + m, a, b, c;
  while(loop--) {
    cin >> a >> b >> c;
    if(a == 1) {
      arr[b-1] = c;
      changeNode(1, 0, n-1, b-1);
    } else {
      cout << getSegment(1, 0, n-1, b-1, c-1) << '\n';
    }
  }
}