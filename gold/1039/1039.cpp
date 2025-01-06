#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string swap(string n) {
  pair <int, int> small = {-1, -1}, big = {-1, -1};

  int temp;
  // for(int i = 0; i < n.size() - 1; i++) {
  //   small = {n[i] - '0', i};
  //   if(small.first == 0) continue;
  //   for(int j = i + 1; j < n.size(); j++) {
  //     temp = n[j] - '0';
  //     if(temp > big.first) {
  //       big = {temp, j};
  //     }
  //   }
  //   if(small.first < big.first) {
  //     n[small.second] = big.first + '0';
  //     n[big.second] = small.first + '0';
  //     return n;
  //   }
  // }
  for(int i = 0; i < n.size() - 1; i++) {
    small = {n[i] - '0', i};
    if(small.first == 0) continue;
    for(int j = i + 1; j < n.size(); j++) {
      temp = n[j] - '0';
      if(temp > small.first) {
        if(temp > big.first) {
          big = {temp, j};
          // cout << big.first << ' ' << big.second << endl;
        } else if(temp == big.first) {
          big.second = j;
        }
      }
    }
    if(big.first != -1) {
      n[big.second] = small.first + '0';
      n[small.second] = big.first + '0';
      return n;
    }
  }

  for(int i = n.size() - 1; i > 0; i--) {
    small = {n[i] - '0', i};
    if(small.first == 0) continue;
    for(int j = i - 1; j >= 0; j--) {
      temp = n[j] - '0';
      if(temp != 0) {
        n[small.second] = n[j];
        n[j] = small.first + '0';
        return n;
      }
    }
  }
  return "-1";
}

int main() {
  string n;
  int k;
  cin >> n >> k;

  while(k--) {
    n = swap(n);
    if(n == "-1") {
      cout << -1;
      return 0;
    }
  }

  cout << n;
}