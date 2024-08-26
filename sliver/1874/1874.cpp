#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector <int> arr;
vector <char> ans;

int main() {
  cin >> n; arr.resize(n);
  for(int i = 0; i < n; i++) cin >> arr[i];

  int max = -1, i = 0, cnt = 1, sw = 1; // sw = 0 => 오류 발생 종료
  stack <int> s;
  while(true) {
    if(!s.empty()) {
      if(s.top() == arr[i]) {
        if(s.top() > max) max = s.top();
        s.pop();
        ans.push_back('-');
        i++;
      } else if(max <= arr[i]) {
        s.push(cnt);
        ans.push_back('+');
        cnt++;
        if(cnt > n) break;
      } else {
        sw = 0;
        break;
      }
    } else {
      s.push(cnt);
      cnt++;
      ans.push_back('+');
    }
    if(i == n) {
      for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
      return 0;
    }
  }

  if(sw) {
    while(!s.empty()) {
      int top = s.top();
      if(top != arr[i]) {
        cout << "NO";
        sw = 0;
        break;
      }
      ans.push_back('-');
      s.pop();
      i++;
    }
    if(sw) for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
  }
  else cout << "NO";
}