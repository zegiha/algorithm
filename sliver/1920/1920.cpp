#include <iostream>
#include <algorithm>
using namespace std;

int have[100000], compare[100000], haveN, compareN;

bool isHave(int n) {
  int left = 0, right = haveN - 1;
  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(n < have[mid]) right = mid - 1;
    else if(n > have[mid]) left = mid + 1;
    else return true;
    // cout << mid << ' ' << left << ' ' << right << endl;
  }
  return false;
}

int main() {
  cin >> haveN;
  for(int i = 0; i < haveN; i++) cin >> have[i];
  sort(have, have + haveN);
  cin >> compareN;
  for(int i = 0; i < compareN; i++) cin >> compare[i];
  // sort(sample, sample + sampleN);
  
  for(int i = 0; i < compareN; i++) {
    if(isHave(compare[i])) cout << "1\n";
    else cout << "0\n";
  }
}