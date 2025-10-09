#include <iostream>
#include <set>

using namespace std;

struct Item {
  int w, v1, v2;
};

int N, W, K;
Item arr[101];
set <pair <int, int>> dp[501];

int main() {
  cin >> N >> W >> K;
  for(int i = 0; i < N; i++) cin >> arr[i].v1 >> arr[i].v2 >> arr[i].w;

  dp[0].insert({0, 0});
  for(auto& it : arr) {
    for(int w = W; w >= it.w; w--) {
      for(pair <int, int> t : dp[w - it.w]) {
        int v1 = t.first, v2 = t.second;
        dp[w].insert({v1 + it.v1, v2 + it.v2});
      }
    }
  }
}