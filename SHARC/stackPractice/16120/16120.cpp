#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str, ch = {'P', 'P', 'A', 'P'};

bool isPPAP(vector <char> s) {
  if(s.size() >= 4) {
    for(int i = 0; i < 4; i++) {
      if(s[s.size() - 4 + i] != ch[i]) return false;
    }
  }
  return true;
}

int main() {
  cin >> str;

  vector <char> s;
  for(int i = 0; i < str.size(); i++) {
    s.push_back(str[i]);
    if(isPPAP(s)) {
      for(int t = 0; t < 3; t++) s.pop_back();
    }
    cout << "check" << s[s.size() - 1] << endl;
  }

  if((s.size() == 1 && s[0] == 'P') || isPPAP(s)) cout << "PPAP";
  else cout << "NP";
}

// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// char check[4] = {'P', 'P', 'A', 'P'};
// string str;

// bool isAllP(stack <char> s) {
//   if(s.top() == 'P') {
//     s.pop();
//     if(s.empty()) return true;
//   } 
//   return false;;
// }

// bool isPPAP(stack <char> s) {
//   int i = 3;
//   while(!s.empty()) {
//     if(s.top() != check[i]) return false;
//     s.pop();
//     i = i == 0 ? 3 : i - 1;
//   }
//   if(i == 3) return true;
//   return false;
// }

// bool isPPAPString(stack <char> s) {
//   if(isAllP(s)) return true;
//   if(isPPAP(s)) return true;
//   return false;
// }

// int main() {
//   cin >> str;

//   int checkN = 0;
//   stack <char> s;
//   for(int i = 0; i < str.size(); i++) {
//     s.push(str[i]);
//     if(s.top() == check[checkN]) checkN++;
//     else checkN = 0;
//     if(checkN == 4) {
//       for(int t = 0; t < 3; t++) s.pop();
//       checkN = 0;
//     }
//   }

//   if(isPPAPString(s)) cout << "PPAP";
//   else cout << "NP";
// }