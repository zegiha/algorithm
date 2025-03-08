#include <iostream>
#include <string>

using namespace std;

int n, m, ans;
bool btn[10];

void solve(string prev) {
    for(int i = 0; i < 10; i++) {
        if(!btn[i]) {
            string current = prev + to_string(i);
            ans = min(ans, (int)(abs(stoi(current) - n) + current.size()));
            if(current.size() < 6) solve(current);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        btn[t] = true;
    }
    ans = abs(100 - n);

    solve("");

    cout << ans;
}