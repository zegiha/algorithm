#include <iostream>

using namespace std;

int n, m, k, arr[6][6], ans;
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool is_area(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

bool visit[6][6] = {0, };
void dfs(int r, int c, int d) {
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         if(visit[i][j]) cout << 'O';
    //         else cout << 'X';
    //     }cout << endl;
    // }

    if(d >= k - 1) {
        // cout << r << ' ' << c << " : =========================\n";
    if(k - 1 == d && r == 0 && c == m - 1) {
            ans++;
        }
        return;
    }

    // cout << "=========================\n";

    for(int i = 0; i < 4; i++) {
        int nr = r + dy[i], nc = c + dx[i];
        if(is_area(nr, nc) && arr[nr][nc] == 1 && !visit[nr][nc]) {
            visit[nr][nc] = true;
            dfs(nr, nc, d + 1);
            visit[nr][nc] = false;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    visit[n-1][0] = true;
    dfs(n - 1, 0, 0);
    visit[n-1][0] = false;

    cout << ans;
}