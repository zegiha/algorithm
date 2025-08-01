#include <iostream>
#include <vector>

using namespace std;
using pii = pair <int, int>;

int n, dp[2][1'000'000];
vector <pair <bool, pii>> arr;

int main() {
  int startIdx = 0;
  char tmpIn, past;
  cin >> n >> tmpIn; past = tmpIn;
  for(int i = 1; i < n; i++) {
    cin >> tmpIn;
    if(past != tmpIn) {
      arr.push_back({past == 'A', {startIdx, i}});
      startIdx = i;
    }
    past = tmpIn;
  }
  arr.push_back({past == 'A', {startIdx, n}});

  if(arr[0].first) {
    dp[0][0] = 1;
  } else {
    dp[1][0] = 1;
  }

  for(int i = 1; i < arr.size(); i++) {
    bool f = arr[i].first;
    int l = arr[i].second.second - arr[i].second.first;
    dp[f][i] = min(
      dp[!f][i-1] + 1,
      dp[f][i-1]
    );
    dp[!f][i] = min(
      dp[!f][i-1] + l,
      dp[f][i-1] + 1 + l
    );
  }

  cout << min(dp[1][arr.size()-1], dp[0][arr.size()-1] + 1);
}