#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n; cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
  } else if (n < 5) {
    cout << -1 << '\n';
  } else {
    int prevOdd = 7, prevEven = 6;
    vector <int> odd, even;
    n -= 5;
    odd.push_back(1);
    odd.push_back(3);
    even.push_back(2);
    bool sw = true;
    while(n--){
      if(!sw) {
        odd.push_back(prevOdd);
        prevOdd += 2;
      } else {
        even.push_back(prevEven);
        prevEven += 2;
      }
      sw = !sw;
    }
    for(int i = 0; i < odd.size(); i++) {
      cout << odd[i] << ' ';
    }
    cout << "5 4 ";
    for(int i = 0; i < even.size(); i++) {
      cout << even[i] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}