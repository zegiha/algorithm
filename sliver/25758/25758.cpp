// 풀이 시간 55m

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans_cnt;
vector <vector <int>> first, second;
bool ans[26] = {0, };

int main() {
  first.resize(26);
  second.resize(26);
  cin >> n;
  string str;
  for(int i = 0; i < n; i++) {
    cin >> str;
    first[str[0]-'A'].push_back(i);
    second[str[1]-'A'].push_back(i);
  }

  for(int i = 0; i < 26; i++) {
    if(first[i].size() > 0) sort(first[i].begin(), first[i].end());
    if(second[i].size() > 0) sort(second[i].begin(), second[i].end());
  }

  for(int i = 0; i < 26; i++) {
    if(first[i].size() > 0) {
      for(int j = i; j < 26; j++) {
        if(!ans[j] && second[j].size() > 0) {
          if(!(second[j].size() == 1 && second[j][0] == first[i][0] && first[i].size() == 1)) {
            ans[j] = true;
            ans_cnt++;
          }
        }
      }
    }
  }

  for(int i = 0; i < 26; i++) {
    if(second[i].size() > 0) {
      for(int j = i; j < 26; j++) {
        if(!ans[j] && first[j].size() > 0) {
          if(!(first[j].size() == 1 && first[j][0] == second[i][0] && second[i].size() == 1)) {
            ans[j] = true;
            ans_cnt++;
          }
        }
      }
    }
  }

  cout << ans_cnt << '\n';
  for(int i = 0; i < 26; i++) {
    if(ans[i]) printf("%c ", 'A' + i);
  }
}

// #include <iostream>

// using namespace std;

// int n;
// string arr[100'001];
// bool has[26] = {0, };

// int main() {
//   cin >> n;
//   for(int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }

//   for(int i = 0; i < n - 1; i++) {
//     for(int j = i + 1; j < n; j++) {
//       has[arr[i][0] > arr[j][1] ? arr[i][0] - 'A' : arr[j][1] - 'A'] = true;
//       has[arr[i][1] > arr[j][0] ? arr[i][1] - 'A' : arr[j][0] - 'A'] = true;
//     }
//   }

//   int ans_cnt = 0;
//   for(int i = 0; i < 26; i++) if(has[i]) ans_cnt++;
//   cout << ans_cnt << '\n';
//   for(int i = 0; i < 26; i++) {
//     if(has[i]) printf("%c ", 'A' + i);
//   }
// }