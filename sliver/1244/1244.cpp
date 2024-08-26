#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> arr;

bool isArea(int cp) {
  if(cp >= 1 && cp <= n) return true;
  return false;
}

void change(int index) {
  if(arr[index] == 0) arr[index] = 1;
  else arr[index] = 0;
}

void man(int swN) {
  for(int i = swN; i <= n; i += swN) change(i);
}

void woman(int swN) {
  int start = swN, end = swN;
  while(true) {
    int newStart = start - 1, newEnd = end + 1;
    if(isArea(newStart) && isArea(newEnd)) {
      if(arr[newStart] == arr[newEnd]) {
        start = newStart;
        end = newEnd;
      } else {
        break;
      }
    } else {
      break;
    }
  }

  for(int i = start; i <= end; i++) {
    change(i);
  }
}

int main() {
  cin >> n;
  arr.push_back(-1);
  for(int i = 1; i <= n; i++) {
    int t; cin >> t;
    arr.push_back(t);
  }
  int t; cin >> t;
  while(t--) {
    int gender, swN;
    cin >> gender >> swN;
    if(gender == 1) {
      man(swN);
    } else {
      woman(swN);
    }
  }

  for(int i = 1; i <= n; i++) {
    cout << arr[i] << ' ';
    if(i % 20 == 0) cout << '\n';
  }
}