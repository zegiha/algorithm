#include <iostream>

using namespace std;

int dp[1001][1001];
string a, b;

bool is_area(int i, int j) {
    return 0 <= i && i < a.size() && 0 <= j && j < b.size();
}

int get_dp(int i, int j) {
    if(is_area(i, j)) return dp[i][j];
    return 0;
}

void printing(int i, int j) {
    if(!is_area(i, j)) return;
    if(get_dp(i, j) == 0) return;
    if(a[i] == b[j]) {
        printing(i - 1, j - 1);
        cout << a[i];
    } else {
        if(get_dp(i-1, j) > get_dp(i, j-1)) printing(i-1, j);
        else printing(i, j - 1);
    }
}

int main() {
    pair <int, int> ans = {0, 0};
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) dp[i][j] = get_dp(i-1, j-1) + 1;
            else dp[i][j] = max(get_dp(i-1, j), get_dp(i, j-1));

            if(dp[ans.first][ans.second] < dp[i][j]) ans = {i, j};
        }
    }

    // for(int i = 0; i < a.size(); i++) {
    //     for(int j = 0; j < b.size(); j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << ans.first << ' ' << ans.second << '\n';

    cout << dp[ans.first][ans.second] << '\n';
    printing(ans.first, ans.second);
}