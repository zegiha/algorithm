#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    string arr; cin >> arr;

    int ans = 2'100'000'000, cnt = 0;
    bool sw = false;

    // LEFT RED 
    for(int i = 0; i < n; i++) {
        if(sw) {
            if(arr[i] == 'R') cnt++;
        } else if(arr[i] != 'R') sw = true;
    }
    ans = min(ans, cnt); cnt = 0; sw = false;

    // RIGHT RED 
    for(int i = n - 1; i >= 0; i--) {
        if(sw) {
            if(arr[i] == 'R') cnt++;
        } else if(arr[i] != 'R') sw = true;
    }
    ans = min(ans, cnt); cnt = 0; sw = false;

    // LEFT BLUE 
    for(int i = 0; i < n; i++) {
        if(sw) {
            if(arr[i] == 'B') cnt++;
        } else if(arr[i] != 'B') sw = true;
    }
    ans = min(ans, cnt); cnt = 0; sw = false;

    // RIGHT BLUE 
    for(int i = n - 1; i >= 0; i--) {
        if(sw) {
            if(arr[i] == 'B') cnt++;
        } else if(arr[i] != 'B') sw = true;
    }
    ans = min(ans, cnt); cnt = 0; sw = false;

    cout << ans;
}