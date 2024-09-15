#include <iostream>

using namespace std;

int n, ans;
pair <int, bool> arr[10];

int getFrontAndBack(int index) {
  int front = index, back = index;
  while(arr[front].second) {
    front--;
  }
  while(arr[back].second) {
    back++;
  }

  return arr[front].first * arr[back].first;
}

void backtrack(int depth, int sum) {
  if(n - depth == 2) {
    if(ans < sum) ans = sum;
    return;
  }

  for(int i = 1; i < n - 1; i++) {
    if(!arr[i].second) {
      arr[i].second = true;
      backtrack(depth + 1, sum + getFrontAndBack(i));
      arr[i].second = false;
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = false;
  }
  backtrack(0, 0);
  cout << ans;
}