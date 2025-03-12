#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001] = {0, };
string a, b;

int get_dp(int i, int j) {
    if(0 <= i && i < a.size() && 0 <= j && j < b.size()) return dp[i][j];
    else return 0;
}

void printing(int i, int j) {
    if(dp[i][j] == 0) return;
    if(a[i-1] == b[j-1]) {
        printing(i-1, j-1);
        cout << a[i];
    } else {
        if(i-1 >= 0 && j-1 >= 0) dp[i-1][j] > dp[i][j-1] ? printing(i-1, j) : printing(i, j-1);
        else if(i-1 >= 0) printing(i-1, j);
        else if(j-1 >= 0) printing(i, j-1);
        else return;
    }
}

int main() {
    pair <int, int> ans = {0, 0};
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                dp[i][j] = get_dp(i-1, j-1) + 1;
            } else {
                dp[i][j] = max(get_dp(i-1, j), get_dp(i, j-1));
            }
            if(dp[i][j] > dp[ans.first][ans.second]) {
                ans = {i, j};
            }
        }
    }

    cout << dp[ans.first][ans.second] << '\n';
    printing(ans.first, ans.second);
}