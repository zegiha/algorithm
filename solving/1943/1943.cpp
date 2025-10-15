#include <iostream>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int memo[100][100'001], n;
pii arr[100];

int dp(int idx, int price) {
  if(price < 0) return 0;
  if(idx == n) return price == 0;

  if(memo[idx][price] != -1) return memo[idx][price];

  int res = 0;
  for(int i = 0; i <= arr[idx].second; i++) {
    res = max(res, dp(idx + 1, price - arr[idx].first * i));
  }

  return memo[idx][price] = res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while(cin >> n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
      cin >> arr[i].first >> arr[i].second;
      total += arr[i].first * arr[i].second;
    }
    if(total % 2 != 0) cout << 0 << '\n';

    for(int i = 0; i < n; i++) for(int j = 0; j <= total; j++) memo[i][j] = -1;
    dp(0, total / 2);
    bool sw = false;
    for(int i = 0; i < n; i++) {
      if(!sw && memo[i][total / 2] == 1) {
        cout << 1 << '\n';
        sw = true;
        break;
      }
    }
    if(!sw) cout << 0 << '\n';
    // cout << "=========================\n\n";
    // for(int i = 0; i < n; i++) for(int j = 0; j <= total; j++) if(memo[i][j] != -1) cout << i << ", " << j << " : " << memo[i][j] << '\n';
    // cout << "=========================\n\n";
  }
}