#include <iostream>
#include <set>
#include <queue>
#include <string>

using namespace std;

int to_number(string v) {
  int ans = 0;
  for(int i = 0; i < v.size(); i++) {
    ans *= 10;
    ans += v[i] - '0';
  }
  return ans;
}

int main() {
  string n; int k; cin >> n >> k;

  int ans = -1;
  queue <string> q;

  q.push(n);
  while(!q.empty() && k > 0) {
    int size = q.size();
    set <string> s;
    k--;
    while(size--) {
      string v = q.front();
      q.pop();
      for(int i = 0; i < v.size() - 1; i++) {
        char t = v[i];
        for(int j = i + 1; j < v.size(); j++) {
          string new_v = v;
          if(new_v[j] == '0' && i == 0) continue;
          new_v[i] = new_v[j];
          new_v[j] = t;
          if(s.end() == s.find(new_v)) {
            s.insert(new_v);
            q.push(new_v);
          }
          if(k == 0 && ans < to_number(new_v)) {
            ans = to_number(new_v);
          }
        }
      }
    }
  }

  if(k > 0) cout << "-1";
  else cout << ans;
}