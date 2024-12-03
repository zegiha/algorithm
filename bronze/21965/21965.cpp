#include <iostream>

using namespace std;

int arr[100'001], n;

bool isDe(int s) {
  for(int i = s + 1; i < n; i++) {
    if(arr[i - 1] < arr[i]) return false;
  }
  return true;
}

int getDeIdx() {
  for(int i = 1; i < n; i++) {
    if(arr[i] == arr[i - 1]) return -1;
    else if(arr[i] < arr[i - 1]) {
      return i;
    }
  }
  return n;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int deIdx = getDeIdx();
  if(deIdx == -1) cout << "NO";
  else {
    if(isDe(deIdx)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
}