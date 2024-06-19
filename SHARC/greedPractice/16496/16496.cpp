#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <string> arr;

bool compare(string a, string b) {
  if(a == b) return false;

  string ab = a + b;
  string ba = b + a;
  
  if(ab > ba) return true;
  else return false;
}

int main() {
  bool exception = true;
  cin >> n; arr.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    if(arr[i] != "0") exception = false;
  }

  if(exception) {
    cout << 0;
    return 0;
  }
  sort(arr.begin(), arr.end(), compare);
  for(int i = 0; i < n; i++) cout << arr[i];
}

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int n;
// vector <string> arr;

// bool isBig(string root, string compare) {
//   int i = 0;
//   while(i < root.size() && i < compare.size()) {
//     int r = root[i] - 48, c = compare[i] - 48;
//     if()
//   }
//   if(i == compare.size()) return true;
//   else return false;
// }

// int main() {
//   cin >> n; arr.resize(n);
//   for(int i = 0; i < n; i++) cin >> arr[i];
  
//   for(int i = 0; i < n; i++) {
//     for(int j = i; j < n - 1; j++) {
//       if(isBig(arr[i], arr[j])) {
//         string tmp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = tmp;
//       }
//     }
//   }
// }

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n;
// vector <string> arr;

// int getNum(char e) {

// }
// bool compare(string a, string b) {
//   int first = 0, second = 0;
//   string sumString = a + b;
//   for(int i = 0; i < sumString.size(); i++) {
//     first *= 10;
//     first += sumString[i] - 48;
//   }
//   sumString = b + a;
//   for(int i = 0; i < sumString.size(); i++) {
//     second *= 10;
//     second += sumString[i] - 48;
//   }

//   return first > second;
// }

// int main() {
//   cin >> n; arr.resize(n);
//   for(int i = 0; i < n; i++) cin >> arr[i];

//   sort(arr.begin(), arr.end(), compare);
//   for(int i = 0; i < n; i++) cout << arr[i];
// }