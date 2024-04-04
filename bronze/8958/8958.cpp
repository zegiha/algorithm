#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t;
    char str[81];

    cin >> t;
    while(t--) {
        int ans = 0;
        cin >> str;
        for(int i = 0, cnt = 0; i < strlen(str); i++) {
            if(str[i] == 'O') {
                cnt++;
                ans += cnt;
            } else cnt = 0;
        }

        cout << ans << endl;
    }
}