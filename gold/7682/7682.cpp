#include <iostream>

using namespace std;

const int check[8][3] = {
  {1, 4, 7},

  {0, 3, 6},
  {2, 5, 8},

  {0, 4, 8},
  {2, 4, 6},

  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
};

string str;

bool is_line(int i) {
  return str[check[i][0]] == str[check[i][1]] && str[check[i][1]] == str[check[i][2]] && str[check[i][0]] != '.';
}

void solve() {
  int x = 0, o = 0;
  for(int i = 0; i < 9; i++) {
    if(str[i] == 'X') x++;
    else if(str[i] == 'O') o++;
  }

  if(x == o || x-1 == o) {
    if(x + o == 9) {
      if(x == 5) {
        int cnt = 0;
        for(int i = 0; i < 8; i++) {
          if(is_line(i)) {
            if(str[check[i][0]] == 'O') {
              cout << "invalid\n";
              return;
            }
            cnt++;
          }
        }
        if(cnt < 3) {
          cout << "valid\n";
          return;
        }
      }
    } else {
      int cnt = 0;
      for(int i = 0; i < 8; i++) {
        if(is_line(i)) {
          if(str[check[i][0]] == 'O') {
            if(x != o) {
              cout << "invalid\n";
              return;
            }
          } else {
            if(x-1 != o) {
              cout << "invalid\n";
              return;
            }
          }
          cnt++;
        }
      }
      if(cnt == 1) {
        cout << "valid\n";
        return;
      }
    }
  }

  cout << "invalid\n";
}

int main() {
  while(true) {
    cin >> str; if(str == "end") return 0;
    solve();
  }
}











// #include <iostream>

// using namespace std;

// string str;

// const int check[8][3] = {
//   {1, 3, 7},

//   {0, 3, 6},
//   {2, 5, 8},

//   {0, 4, 8},
//   {2, 4, 6},

//   {0, 1, 2},
//   {3, 4, 5},
//   {6, 7, 8},
// };

// const string edge[] = {
//   "XXXXooXoo",
//   "XXXooXooX",
//   "ooXooXXXX",
//   "XooXooXXX",
//   "XoXoXoXoX"
// };

// bool is_line(int idx) {
//   return str[check[idx][0]] == str[check[idx][1]] && str[check[idx][1]] == str[check[idx][2]] && str[check[idx][0]] != '.';
// }

// void solve() {
//   int x = 0, o = 0;
//   for(int i = 0; i < 9; i++) {
//     if(str[i] == 'X') x++;
//     else if(str[i] == 'O') o++;
//   }

//   if(x + o == 9) {
//     if(x == 5) {
//       int cnt = 0;
//       for(int i = 0; i < 8; i++) {
//         if(is_line(i)) {
//           cnt++;
//           if(str[check[i][0]] == 'O') {
//             cout << "invalid\n";
//             return;
//           }
//         }
//       }
//       if(cnt < 3) {
//         cout << "valid\n";
//       }
//     }
//   } else if(x == o || x - 1 == o) {
//     int cnt = 0;
//     for(int i = 0; i < 8; i++) {
//       if(is_line(i)) {
//         if(cnt > 0) {
//           cout << "invalid\n";
//           return;
//         }
//         cnt++;
//         if(str[check[i][0]] == 'O') {
//           if(x != o) {
//             cout << "invalid\n";
//             return;
//           }
//         } else {
//           if(x - 1 != o) {
//             cout << "invalid\n";
//             return;
//           }
//         }
//       }
//     }

//     if(cnt == 1) {
//       cout << "valid\n";
//       return;
//     }
//   }

//   cout << "invalid\n";
// }

// int main() {
//   while(true) {
//     cin >> str;
//     if(str == "end") {
//       break;
//     }
//     solve();
//   }
// }