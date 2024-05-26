#include <iostream>
#include <string>
using namespace std;

int num[53], str[53], n, decoding[2][101];

// 해독 가능한 경우
// 같은 소문자의 개수와 같은 소문자 치환 숫자의 개수가 같아야 함
// 같은 대문자의 개수와 같은 대문자 치환 숫자의 개수가 같아야 함
// 공백의 개수와 공백 치완 숫자의 개수가 같아야 함
// 이걸로 착각한 나 시발

// bool capital() {
//   int max = 0;
//   for(int i = 1; i <= 26; i++) {
//     if(str[i] > max) max = str[i];
//     decoding[1][str[i]]++;
//   }
//   for(int i = 1; i <= 26; i++) {
//     if(num[i] > max) return false;
//     decoding[0][num[i]]++;
//   }
//   for(int i = 1; i <= max; i++) {
//     if(decoding[0][i] != decoding[1][i]) return false;
//   }
//   return true;
// }

// bool upper() {
//   int max = 0;
//   for(int i = 27; i <= 52; i++) {
//     if(str[i] > max) max = str[i];
//     decoding[1][str[i]]++;
//   }
//   for(int i = 27; i <= 52; i++) {
//     if(num[i] > max) return false;
//     decoding[0][num[i]]++;
//   }
//   for(int i = 1; i <= max; i++) {
//     if(decoding[0][i] != decoding[1][i]) return false;
//   }
//   return true;
// }

int main() {
  cin >> n;
  for(int i = 0, t; i < n; i++) {
    cin >> t;
    num[t]++;
  }

  cin.ignore();
  string tmp;
  getline(cin, tmp);
  for(int i = 0; i < tmp.size(); i++) {
    char c = tmp[i];
    if(c == ' ') str[0]++;
    else if(c <= 'Z') str[c - 'A' + 1]++;
    else str[c - 'a' + 27]++;
    // if(c == 'z') cout << c - 'a';
  }

  // for(int i = 1; i < 53; i++) {
  //   cout << str[i] << ' ' << num[i] << '\n';
  // }
  // cout << endl;

  for(int i = 0; i < 53; i++) {
    if(num[i] != str[i]) {
      cout << 'n';
      return 0;
    }
  }

  cout << 'y';
}
