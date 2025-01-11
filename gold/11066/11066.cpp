#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501], arr[501], n, psum[501];

int get_dp(int s, int e) {
    if(dp[s][e] != 2'100'000'000) return dp[s][e];
    if(s == e) return 0;

    for(int i = s; i < e; i++) {
        dp[s][e] = min(dp[s][e], get_dp(s, i) + get_dp(i + 1, e));
    }

    return dp[s][e] += (psum[e] - (s == 0 ? 0 : psum[s - 1]));
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        psum[i] = arr[i];
        if(i != 0) {
            psum[i] += psum[i - 1];
        }
        for(int j = 0; j < n; j++) {
            dp[i][j] = 2'100'000'000;
        }
    }
    
    cout << get_dp(0, n-1) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}