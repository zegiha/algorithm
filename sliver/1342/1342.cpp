#include <iostream>
#include <vector>

using namespace std;

int ans = 0, char_arr[26] = {0, };
vector <char> arr;

bool visit[10];
void backtrack(vector <char> str, int depth) {
  if(depth == arr.size()) {
    ans++;
    return;
  }

  for(int i = 0; i < arr.size(); i++) {
    if(visit[i] || (depth > 0 && arr[i] == str[depth - 1])) continue;

    visit[i] = true;
    str.push_back(arr[i]);
    backtrack(str, depth + 1);
    visit[i] = false;
    str.pop_back();
  }
}

void divide_factorial() {
  int facs = 1;

  for(int cnt : char_arr) {
    for(int i = 1; i <= cnt; i++){
      facs *= i;
    }
    // cout << facs <<  ' ';
  }

  // cout << '\n' << ans << ' ' << facs << '\n';
  ans = ans / facs;
}

int main() {
  string temp; cin >> temp;
  for(char c : temp) {
    arr.push_back(c);
    char_arr[c-'a']++;
  }

  backtrack(vector <char> (0), 0);
  // divide_factorial();

  cout << ans;
}