#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> arr;

int isPalindrome() {
  int start, end;
  cin >> start >> end;
  for(int i = 0; i < (end - start) / 2; i++) {
    if(arr[start + i] != arr[end - i]) return 0;
  }
  return 1;
}

int main() {
  int t;
  cin >> n;
  arr.resize(n + 2);
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  cin >> t;
  while(t--) {
    cout << isPalindrome();
  }
}