#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
using pii = pair <int, int>;

int n, k;
pii arr[1001];

bool isReached(pii from, pii to, int gas) {
  int distance = ceil(sqrt(pow(from.first - to.first, 2) + pow(from.second - to.second, 2)));
  int cost = distance / 10;

  if(distance % 10 != 0) cost++;


  // cout << "==================\n" << "from : " << from.first << ", " << from.second << "\nto : " << to.first << ", " << to.second << "\ndistance : " << distance << "\ncost : " << cost << '\n';

  return cost <= gas;
}

bool isAvailableGas(int gas) {
  int cnt = 0;
  queue <int> q;
  bool v[1001] = {0, };

  q.push(-1);

  while(!q.empty() && cnt <= k) {
    int size = q.size();
    cnt++;

    while(size--) {
      pii pos = q.front() != -1 ? arr[q.front()] : make_pair(0, 0);

      q.pop();

      if(isReached(pos, {10000, 10000}, gas)) {
        return true;
      }

      for(int i = 0; i < n; i++) {
        if(
          v[i] ||
          !isReached(pos, arr[i], gas)
        ) {
          continue;
        }

        q.push(i);
        v[i] = true;
      }
    }
  }

  return false;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

  int
  l = 0,
  r = 15'000,
  mid,
  ans = 15'000;

  while(l <= r) {
    mid = (l + r) / 2;

    if(isAvailableGas(mid)) {
      r = mid - 1;
      ans = min(ans, mid);
    } else {
      l = mid + 1;
    }
  }

  cout << ans;

  // cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

  // cout << isAvailableGas(634) << '\n';
}