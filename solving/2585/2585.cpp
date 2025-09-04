#include <iostream>
#include <cmath>
#include <queue>

#define INF 2'100'000'000

using namespace std;
using pii = pair <int, int>;

int n, k, ans = INF;
pii g[1001], e = {10000, 10000};

bool isPosEnd(pii pos) {
  return pos.first == e.first && pos.second == e.second;
}

int getDistance(pii from, pii to) {
  return ((from.first - to.first) * (from.first - to.first)) + ((from.second - to.second) * (from.second - to.second));
}

// bool v[1002];
// void solve(pii pos, int maxLength, int via) {
//   // cout << "===========================" << pos.first << ' ' << pos.second << '\n';
//   if(isPosEnd(pos)) {

//     // cout << "1 : " << maxLength << '\n';
//     ans = min(ans, maxLength);
//     return;
//   }

//   if(via == k) {
//     maxLength = max(maxLength, getDistance(pos, e));


//     // cout << "2 : " << maxLength << '\n';
//     ans = min(ans, maxLength);
//     return;
//   }

//   for(int i = 0; i < n; i++) {
//     if(v[i]) continue;

//     v[i] = true;
//     solve(g[i], max(maxLength, getDistance(pos, g[i])), via + 1);
//     v[i] = false;
//   }

//   solve(e, max(maxLength, getDistance(pos, e)), via + 1);
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> k;

  int a, b;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    g[i] = {a, b};
  }

  // solve({0, 0}, INF * -1, 0);

  queue <pii> q;
  bool v[1001] = {0, };

  while(!q.empty()) {
    int idx = q.front().first, maxLength = q.front().second;

    
  }

  double sqrtDistance = sqrt(ans);
  int flooredSqrtDistance = floor(sqrtDistance), distance;

  distance = flooredSqrtDistance;
  if(sqrtDistance - (double)flooredSqrtDistance != 0) distance++;

  ans = distance / 10;
  ans += distance % 10 != 0 ? 1 : 0;

  cout << ans;
}