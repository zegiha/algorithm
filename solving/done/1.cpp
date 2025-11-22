#include <iostream>

using namespace std;

int main() {
    int s, e, current = 1, cnt = 0, ans = 0;
    cin >> s >> e;
    for(int i = 1; i <= s; i++) {
        if(current == cnt) {
            current++;
            cnt = 0;
        }
        cnt++;
    }

    while(s <= e) {
        // cout << current << '\n';
        ans += current;
        if(current == cnt) {
            current++;
            cnt = 0;
        }
        s++;
        cnt++;
    }

    cout << ans;
}