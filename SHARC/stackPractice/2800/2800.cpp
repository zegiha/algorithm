#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int n;
bool delChar[201], visit[201];
vector <pair <int, int>> bracket;
set <string> ans;
string str;

void setBracket() {
  stack <int> s;
  for(int i = 0; i < n; i++) {
    if(str[i] == '(') {
      s.push(i);
    }
    else if(str[i] == ')') {
      bracket.push_back({s.top(), i});
      s.pop();
    }
  }
}

void getAns(int cnt, int index) {
  if(cnt >= 1) {
    string newAns = "";
    for(int i = 0; i < n; i++) {
      if(delChar[i]) continue;
      newAns += str[i];
    }
    ans.insert(newAns);
  }

  for(int i = index; i < bracket.size(); i++) {
    if(visit[i]) continue;
    visit[i] = true;
    delChar[bracket[i].first] = true;
    delChar[bracket[i].second] = true;

    getAns(cnt + 1, index + 1);

    visit[i] = false;
    delChar[bracket[i].first] = false;
    delChar[bracket[i].second] = false;
  }
}

int main() {
  cin >> str; n = str.size();
  setBracket();
  getAns(0, 0);
  for(auto ansItem : ans) {
    cout << ansItem << '\n';
  }
}