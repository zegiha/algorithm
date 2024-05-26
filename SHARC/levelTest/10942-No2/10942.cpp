#include <iostream>
#include <stdio.h>
using namespace std;

int n, t;
int d[2001], pal[2001][2001];

void getPal() {
  for(int i = 1; i <= n; i++){
     pal[i][i] = 1;
  }
  for(int i = 1; i < n; i++) {
    if(d[i] == d[i + 1]) pal[i][i + 1] = 1;
  }
  for(int i = n - 1; i >= 1; i--) {
    for(int j = i + 2; j <= n; j++)
      if(pal[i + 1][j - 1] == 1 && d[i] == d[j]) pal[i][j] = 1;
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  getPal();

  cin >> t;
  for(int i = 1; i <= t; i++) {
    int s, e;
    cin >> s;
    cin >> e;
    cout << pal[s][e] << '\n';
  }
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int n;
// vector <vector <int>> arr;

// // int solve() {
// //   int s, e; cin >> s >> e;
// //   for(; s < e; s++, e--) {
// //     if(arr[s][e] == -1) {
// //       if(arr[s][0] == arr[0][e]) arr[s][e] = 1;
// //       else {
// //         arr[s][e] = 0;
// //         return 0;
// //       }
// //     } else if(!arr[s][e]) return 0;
// //   }
// //   return 1;
// // }

// int main() {
//   int t;
//   cin >> n;
//   arr.resize(n + 2, vector <int> (n + 2, -1));
//   for(int i = 1; i <= n; i++) {
//     int input; cin >> input;
//     arr[i][0] = input;
//     arr[0][i] = input;
//   }
//   //이거를 채우고 정보를 보면서해버리면 시간초과가 남
//   for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) arr[i][j] = arr[0][j] == arr[i][0];
//   // for(int i = 1; i <= n; i++) {
//   //   for(int j = 1; j <= n; j++) {
//   //     if(arr[i][j] == 1) cout << "O ";
//   //     else cout << "X ";
//   //   }
//   //   cout << endl;
//   // }
  
//   cin >> t;
//   while(t--) {
//     // cout << solve() << endl;
//     int a, b;
//     cin >> a >> b;
//     cout << arr[a][b] << endl;
//   }
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int n;
// vector <int> arr;

// int isPalindrome() {
//   int start, end;
//   cin >> start >> end;
//   for(int i = 0; i < (end - start) / 2; i++) {
//     if(arr[start + i] != arr[end - i]) return 0;
//   }
//   return 1;
// }

// int main() {
//   int t;
//   cin >> n;
//   arr.resize(n + 2);
//   for(int i = 1; i <= n; i++) {
//     cin >> arr[i];
//   }
//   cin >> t;
//   while(t--) cout << isPalindrome();
// }