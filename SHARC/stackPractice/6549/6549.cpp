#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int ans = 0;
vector <int> arr;
string str;

void getArr() {
  int i = 0;
  while(i < str.size()) {
    int n = 0;
    while(str[i] !=  ' ' && i < str.size()) {
      n *= 10;
      n += (str[i] - 48);
      i++;
    }
    arr.push_back(n);
    i++;
  }
}

void solve() {
  int i = 0;
  stack <pair <int, int>> s;
  s.push(make_pair(i + 1, arr[i])); i++;
  while(i < arr.size()) {
    if(!s.empty()) {
      if(s.top().second > arr[i]) {
        int width = (i + 1) - s.top().first, height = s.top().second;
        if(ans < width * height) ans = width * height;
        s.pop();
      } else {
        s.push(make_pair(i + 1, arr[i]));
        i++;
      }
    } else {
      s.push(make_pair(i + 1, arr[i]));
      i++;
    }
    // cout << s.top().first << ' ' << s.top().second << '\n';
  }

  while(!s.empty()) {
    int width = arr.size() - s.top().first + 1, height = s.top().second;
    if(ans < width * height) ans = width * height;

    s.pop();
  }

  cout << ans << '\n';
}

int main() {
  while(true) {
    getline(cin, str);
    if(str == "0") break;
    getArr();
    
    solve();

    ans = 0;
    arr.clear();
  }
}