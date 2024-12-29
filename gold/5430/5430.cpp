#include <iostream>
#include <vector>

using namespace std;

void solve() {
  string func, array;
  int size;
  vector <int> arr;

  cin >> func >> size >> array;

  int t = 0, v = 0;
  while(size) {
    if(array[t] >= '0' && array[t] <= '9') {
      v *= 10;
      v += array[t] - '0';
    } else {
      if(v != 0) {
        arr.push_back(v);
        size--;
      }
      v = 0;
    }
    t++;
  }

  bool isFront = true;

  for(int i = 0; i < func.size(); i++) {
    if(func[i] == 'R') {
      isFront = !isFront;
    } else {
      if(arr.size() == 0) {
        cout << "error\n";
        return;
      }
      if(isFront) {
        arr.erase(arr.begin());
      } else {
        arr.pop_back();
      }
    }
  }

  if(isFront) {
    cout << '[';
    for(int i = 0; i < arr.size(); i++) {
      cout << arr[i];
      if(i + 1 == arr.size()) cout << "]\n";
      else cout << ',';
    }
  } else {
    cout << '[';
    for(int i = arr.size()-1; i >= 0; i--) {
      cout << arr[i];
      if(i == 0) cout << "]\n";
      else cout << ',';
    }
  }

  return;
}

int main() {
  int t; cin >> t;
  while(t--) {
    solve();
  }
}