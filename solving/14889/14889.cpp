#include <iostream>

using namespace std;

int n, arr[20][20], ans = 2'100'000'000;

bool c[20] = {0,};
void solve(int d, int l, int s) {
    if(d == n/2) {
        cout << l << ' ' << s << '\n';
        ans = min(ans, abs(l-s));
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!c[i]) {
            int sum1 = 0, sum2 = 0;
            for(int j = 0; j < n; j++) {
                if(c[j]) sum1 += arr[i][j] + arr[j][i];
                sum2 += arr[i][j] + arr[j][i];
            }
            c[i] = true;
            solve(d + 1, s + sum1, l - sum2);
            c[i] = false;
        }
    }
}

int main() {
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    solve(0, 0, sum);

    cout << ans;
}