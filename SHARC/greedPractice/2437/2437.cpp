#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> arr;

int main() {
  cin >> n;
  for(int i = 0, tmp; i < n; i++) {
    cin >> tmp; arr.push_back(tmp);
  }

  sort(arr.begin(), arr.end());
  int mostBig = 1;
  for(int i = 0; i < n; i++) {
    if(mostBig < arr[i]) {
      cout << mostBig;
      return 0;
    }
    mostBig += arr[i];
  }

  cout << mostBig;
  return 0;
}

// 처음 값이 1이라서 모든 값에 사실상 1이 더해져 있다고 생각하면 만들 수 없는 수는 mostBig이고, mostBig - 1이 만들 수 있는 최대의 수라고 보는게 맞을 듯 ㅇㅇ