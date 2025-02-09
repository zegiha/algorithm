#include <iostream>

using namespace std;

int n, arr[101][101];
long long dp[101][101];

long long get_dp(int r, int c) {
    if(dp[r][c] != -1) return dp[r][c];
    if(r == 0 && c == 0) {
        dp[r][c] = 1;
        return dp[r][c];
    }

    long long new_dp = 0;
    for(int i = 0; i < r; i++) {
        if(arr[i][c] + i == r) {
            new_dp += get_dp(i, c);
        }
    }
    for(int j = 0; j < c; j++) {
        if(arr[r][j] + j == c) {
            new_dp += get_dp(r, j);
        }
    }

    dp[r][c] = new_dp;
    return dp[r][c];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << get_dp(n-1, n-1);
}

// #include <iostream>
// #include <queue>

// using namespace std;

// int n, arr[101][101], dy[] = {1, 0}, dx[] = {0, 1};
// long long ans;
// bool visit[101][101];

// bool is_area(int r, int c) {
//     return 0 <= r && r < n && 0 <= c && c < n;
// }

// int main() {
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> arr[i][j];
//         }
//     }

//     queue <pair <int, int>> q;

//     q.push({0, 0});
//     visit[0][0] = true;

//     while(!q.empty()) {
//         int r = q.front().first, c = q.front().second;
//         q.pop();

//         for(int d = 0; d < 2; d++) {
//             int nr = r + dy[d] * arr[r][c], nc = c + dx[d] * arr[r][c];
//             if(is_area(nr, nc)) {
//                 if(nr == n - 1 && nc == n - 1) {
//                     ans++;
//                 } else if(!visit[nr][nc]) {
//                     q.push({nr, nc});
//                     visit[nr][nc] = true;
//                 }
//             }
//         }
//     }

//     cout << ans;
// }