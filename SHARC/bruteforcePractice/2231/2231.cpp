#include <iostream>

using namespace std;

int n;

int getDivide(int i) {
  int sum = 0;
  while(i) {
    sum += i % 10;
    i /= 10;
  }
  return sum;
}

int main() {
  cin >> n;

  int i = 1;
  while(i < n) {
    int sum = i;
    sum += getDivide(i);
    if(sum == n) {
      cout << i;
      return 0;
    }
    i++;
  }

  cout << 0;
  return 0;
}