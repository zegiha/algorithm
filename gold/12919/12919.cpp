#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible = false;
void solve(string s, string t) {
    if(s == t) {
        isPossible = true;
        return;
    }
    if(s.size() >= t.size()) return;
    string tmp;
    if(!isPossible && t[t.size()-1] == 'A') {
        tmp = t;
        tmp.pop_back();
        solve(s, tmp);
    }
    if(!isPossible && t[0] == 'B') {
        tmp = t;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        solve(s, tmp);
    }
}

int main() {
    string s, t;
    cin >> s >> t;

    solve(s, t);

    cout << isPossible;
}
