#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector <vector <vector <int>>> arr;

int main() {
  cin >> n;
  string str;
  arr.resize(n, vector <vector <int>> (0));
  for(int i = 0; i < n; i++) {
    cin >> str;
    arr[i].resize(str.size());
    for(int j = 0; j < str.size(); j++) {
      if(arr[i][j].size() == 0) {
        arr[i][j].push_back(j);
        for(int k = j + 1; k < str.size(); k++) {
          if(str[j] == str[k]) {
            arr[i][j].push_back(k);
            arr[i][k].push_back(-1);
          }
        }
      }
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < str.size(); j++) {
  //     for(int k = 0; k < arr[i][j].size(); k++) cout << arr[i][j][k] << ' ';
  //     cout << '\n';
  //   }
  //   cout << "==================\n";
  // }

  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      bool sw = true;
      for(int k = 0; k < str.size(); k++) {
        if(arr[i][k].size() == arr[j][k].size()) {
          for(int l = 0; l < arr[i][k].size(); l++) {
            if(arr[i][k][l] != arr[j][k][l]) {
              sw = false;
              break;
            }
          }
        } else {
          sw = false;
          break;
        }
      }
      if(sw) ans++;
    }
  }
  
  cout << ans;
}