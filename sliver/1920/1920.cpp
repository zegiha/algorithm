#include <iostream>
#include <algorithm>
using namespace std;

int have[100000], sample[100000], haveN, sampleN;

bool isHave(int n) {
  int mid = (haveN - 1) / 2, left = 0, right = haveN - 1;
  while(left < right) {
    if(n < have[mid]) right = mid - 1;
    else if(n > have[mid]) left = mid + 1;
    else return true;
    mid = (right - left) / 2;
    cout << mid << ' ' << left << ' ' << right << endl;
  }
  if(n == have[left] || n == have[right]) return true;
  else return false;
}

int main() {
  cin >> haveN;
  for(int i = 0; i < haveN; i++) cin >> have[i];
  sort(have, have + haveN);
  cin >> sampleN;
  for(int i = 0; i < sampleN; i++) cin >> sample[i];
  sort(sample, sample + sampleN);
  
  for(int i = 0; i < sampleN; i++) {
    if(isHave(sample[i])) cout << "1\n";
    else cout << "0\n";
  }
}