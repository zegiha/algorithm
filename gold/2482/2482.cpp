#include <iostream>

using namespace std;

int n, k;

int getRecurrenceRelation() {
  return n - 1 - (2 * (k - 1));
}

int main() {
  cin >> n >> k;

  if(k == 1) {
    cout << n;
    return 0;
  }
  
  int ans = getRecurrenceRelation();
  if(ans <= 0) {
    cout << 0;
    return 0;
  }

  int i = 0, ansCpy = ans;
  long long tmp = ansCpy * ( 2 + (ansCpy - 1)) / 2;

  ans += tmp % 1'000'000'003;

  cout << ans;
  return 0;
}