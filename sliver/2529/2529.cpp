#include <iostream>
#include <vector>

using namespace std;

int k, arr[10];

bool recorded[10];
vector <vector <int>> check;
vector <int> record;

bool isPrint() {
  for(int index = 0; index < check.size(); index++) {
    for(int i = 0; i < k; i++) {
      bool sw = true;
      if(check[index][i] != record[i]) {
        sw = false;
        break;
      }
      if(sw) return true;
    }
  }
  return false;
}

void backtrack(int depth, int last) {
  if(depth == k) {
    if(!isPrint()) {
      for(int i = 0; i < record.size(); i++) cout << record[i];
      cout << '\n';
      check.push_back(record);
    }
    return;
  }

  if(arr[depth] == 0) {
    for(int e = last - 1; e >= 0; e--) {
      if(!recorded[e]) {
        recorded[e] = true;
        record.push_back(e);
        backtrack(depth + 1, e);
        recorded[e] = false;
        record.pop_back();
      }
    }
  } else {
    for(int e = 9; e > last; e--) {
      if (!recorded[e]) {
        recorded[e] = true;
        record.push_back(e);
        backtrack(depth + 1, e);
        recorded[e] = false;
        record.pop_back();
      }
    }
  }
}

int main() {
  cin >> k;
  for(int i = 0; i < k; i++) {
    char t; cin >> t;
    if(t == '>') arr[i] = 0;
    else arr[i] = 1;
  }
  for(int e = 9; e >= 0; e--) {
    recorded[e] = true;
    record.push_back(e);
    backtrack(0, e);
    recorded[e] = false;
    record.pop_back();
  }
  
  for(int i = 0; i < check[0].size(); i++) cout << check[0][i]; cout << '\n';
  for(int i = 0; i < check[check.size() - 1].size(); i++) cout << check[check.size() - 1][i];
}