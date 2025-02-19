#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <string, bool, greater<>> arr;
int n;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    string a, b; cin >> a >> b;
    if(b == "enter") arr[a] = true;
    else arr[a] = false;
  }

  for(map <string, bool>::iterator it = arr.begin(); it != arr.end(); it++) {
    if(it->second) cout << it->first << '\n';
  }
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// int n;
// vector <string> arr, del;

// bool cmp(string a, string b) {
//   return a > b;
// }

// int get_idx(string name) {
//   int l = 0, r = arr.size() - 1, m;

//   while(l <= r) {
//     m = (l + r) / 2;
//     if(arr[m] > name) {
//       l = m + 1;
//     } else if(arr[m] < name) {
//       r = m - 1;
//     } else {
//       return m;
//     }
//   }
// }

// int main() {
//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     string name, cmd; cin >> name >> cmd;
//     if(cmd == "enter") {
//       arr.push_back(name);
//     } else {
//       del.push_back(name);
//     }
//   }

//   sort(arr.begin(), arr.end(), cmp);
//   for(int i = 0; i < del.size(); i++) {
//     arr.erase(arr.begin() + get_idx(del[i]));
//   }

//   for(int i = 0; i < arr.size(); i++) cout << arr[i] << '\n';
// }