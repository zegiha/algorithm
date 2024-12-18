#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, kim, lim;
  cin >> n >> kim >> lim;

  vector <bool> arr(n + 1, false);
  arr[kim] = true; arr[lim] = true;

  int ans = 0;
  while(arr.size() - 1 >= 1) {
    ans++;
    vector <bool> new_arr; new_arr.push_back(false);
    // cout << "size : " << arr.size() << '\n';
    for(int i = 1; i < arr.size() - 1; i += 2) {
      if(arr[i] && arr[i + 1]) {
        cout << ans;
        return 0;
      }
      if(arr[i] || arr[i + 1]) new_arr.push_back(true);
      else new_arr.push_back(false);
    }
    if((arr.size() - 1) % 2 != 0) {
      if(arr[arr.size() - 1]) new_arr.push_back(true);
      else new_arr.push_back(false);
    }
    arr = new_arr;
  }
  cout << -1;
}