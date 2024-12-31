#include <iostream>

using namespace std;

void solve() {
  string cmd, in;
  int arr[100'001], size;
  cin >> cmd >> size >>in;
  
  int v = 0, idx = 0;
  for(char c : in) {
    if(c >= '0' && c <= '9') {
      v *= 10;
      v += c - '0';
    } else if((c == ']' || c == ',') && idx < size) {
      arr[idx++] = v;
      v = 0;
    }
  }

  bool isReverse = false;
  int front = 0, back = size;
  for(char c : cmd) {
    if(c == 'R') {
      isReverse = !isReverse;
    } else if(c == 'D') {
      if(isReverse) {
        back--;
      } else {
        front++;
      }
    }
  }

  if(!(front <= back)) {
    cout << "error\n";
  } else if(front == back) {
    cout << "[]\n";
  } else {
    cout << '[';
    if(isReverse) {
      for(int i = back - 1; i >= front; i--) {
        cout << arr[i];
        if(i != front) cout << ',';
      }
    } else {
      for(int i = front; i < back; i++) {
        cout << arr[i];
        if(i + 1!= back) cout << ',';
      }
    }
    cout << "]\n";
  }
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}