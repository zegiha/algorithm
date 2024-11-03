#include <iostream>
#include <algorithm>

using namespace std;

int n, ball[31];
bool isMake[40'001], dp[31][40'001];

void createDp(int i, int w) {
  if(i > n) return;
  if(dp[i][w]) return;
  dp[i][w] = true;
  isMake[w] = true;

  createDp(i + 1, w);
  createDp(i + 1, w + ball[i]);
  createDp(i + 1, abs(w - ball[i]));
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> ball[i];
  createDp(0, 0);
  
  int t; cin >> t;
  while(t--) {
    int find; cin >> find;
    if(isMake[find]) cout << "Y ";
    else cout << "N ";
  } 
  // for(int i = 0; i < 10; i++) {
  //   cout << isMake[i] << endl;
  // }
}