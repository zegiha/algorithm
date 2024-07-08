#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;

void solve() {
  long long ans = 0;
  stack <int> s;
  vector <long long> h(n + 1);
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++) {
    while(!s.empty() && h[s.top()] > h[i]) {
      int prevTop = s.top(); s.pop();
      long long area; // long long 중요함, 넓이 최대 값이 넘어감
      if(s.empty()) {
        area = h[prevTop] * i; // 7 6 5 4 3 반례에서 알 수 있듯 현재의 스택이 비어 있으면 i ( n번의 루프를 끝낸 후는 n ) 으로 넓이를 계산해야함
      }
      else {
        area = h[prevTop] * (i - s.top() - 1); // 바로 위 주석으로 인해 pop이후 한번 더 empty를 확인하고 아직 스택이 남아있다면 i - s.top() - 1으로 계산
      }

      if(area > ans) ans = area;
    }
    s.push(i);
  }
  while(!s.empty()) {
    long long prevHTop = h[s.top()], area;
    s.pop();
    if(s.empty()) {
      area = prevHTop * n;
    }
    else {
      area = prevHTop * (n - s.top() - 1);
    }

    if(area > ans) ans = area;
  }

  cout << ans << '\n';
}

int main() {
  while(true) {
    cin >> n; if(n == 0) break;
    solve();
  }
}

// --------------------정답 코드---------------------
// #include <iostream>
// #include <stack>

// using namespace std;

// int n;
// long long ans, h[100002];

// void solve() {
//  stack <int> s;
//   for(int i = 0; i < n; i++) cin >> h[i];
//   for(int i = 0; i < n; i++) {
//     while(!s.empty() && h[s.top()] > h[i]) {
//       long long hTop = h[s.top()];
//       int l = i;
//       s.pop();

//       if(!s.empty()) l = i - s.top() - 1;
//       if(l * hTop > ans) ans = l * hTop;
//     }
//     s.push(i);
//   }
//   while(!s.empty()) {
//     long long hTop = h[s.top()];
//     int l = n;
//     s.pop();
    
//     if(!s.empty()) {
//       l = n - s.top() - 1;
//     }

//     if(l * hTop > ans) ans = l * hTop;
//   }

//   cout << ans << '\n';
// }

// int main() {
//   while(true) {
//     cin >> n;
//     if(n == 0) break;
//     solve();
//     ans = 0;
//   }
// }
// --------------------------------------------------

// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// int n, h[100002];

// void solve() {
//   int ansArea = 0;
//   stack <int> s;
//   for(int i = 1; i <= n; i++) cin >> h[i];
//   s.push(0);
//   for(int i = 1; i <= n + 1; i++) {
//     while(!s.empty() && h[s.top()] > h[i]) {
//       int check = s.top(); s.pop();
//       int newArea = h[check] * (i - s.top() -1);
//       if(newArea > ansArea) ansArea = newArea;
//     }
//     s.push(i);
//   }

//   cout << ansArea;
// }

// int main() {
//   while(true) {
//     cin >> n; if(!n) break;
//     solve();
//   }
// }

// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;

// int n;
// stack <int> s;

// void solve() {
//   int h[100002] = {0,}, ans = 0;
//   for(int i = 1; i <= n; i++) cin >> h[i];
//   s.push(0);
//   for(int i = 1; i <= n + 1; i++) {
//     while(!s.empty() && h[s.top()] > h[i]) {
//       int top = s.top(); s.pop();
//       int area = h[top] * (i - s.top() - 1);
//       if(area > ans) ans = area;
//     }
//     s.push(i);
//   }
//   cout << ans << '\n';
// }

// int main() {
//   while(true) {
//     cin >> n; if(!n) break;
//     solve();
//   }
// }

// 처음에 입력값 수 N이 주어짐 시바;;;

// #include <iostream>
// #include <stack>
// #include <vector>
// #include <string>

// using namespace std;

// int ans = 0;
// vector <int> arr;
// string str;

// void getArr() {
//   int i = 0;
//   while(i < str.size()) {
//     int n = 0;
//     while(str[i] !=  ' ' && i < str.size()) {
//       n *= 10;
//       n += (str[i] - 48);
//       i++;
//     }
//     arr.push_back(n);
//     i++;
//   }
// }
// void solve() {

//   int i = 0;
//   stack <pair <int, int>> s;
//   s.push(make_pair(i + 1, arr[i])); i++;
//   while(i < arr.size()) {
//     if(!s.empty()) {
//       if(s.top().second > arr[i]) {
//         int width = (i + 1) - s.top().first, height = s.top().second;
//         if(ans < width * height) ans = width * height;
//         s.pop();
//       } else {
//         s.push(make_pair(i + 1, arr[i]));
//         i++;
//       }
//     } else {
//       s.push(make_pair(i + 1, arr[i]));
//       i++;
//     }
//     // cout << s.top().first << ' ' << s.top().second << '\n';
//   }

//   while(!s.empty()) {
//     int width = arr.size() - s.top().first + 1, height = s.top().second;
//     if(ans < width * height) ans = width * height;

//     s.pop();
//   }

//   cout << ans << '\n';
// }

// int main() {
//   while(true) {
//     getline(cin, str);
//     if(str == "0") break;
//     getArr();
    
//     solve();

//     ans = 0;
//     arr.clear();
//   }
// }