#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    bool sw[42] = {false, };
    for(int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;

        if(!sw[tmp % 42]) {
            ans++;
            sw[tmp % 42] = true;
        }
    }

    cout << ans;
}