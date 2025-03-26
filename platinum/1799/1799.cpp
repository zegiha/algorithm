#include <iostream>

using namespace std;

int n, arr[10][10], ans[2], idx;
bool u[20] = {0, }, d[20] = {0, };

void backtrack(int r, int c, int cnt) {
    if(c >= n) {
        c = c % 2 == 0 ? 1 : 0;
        r++;
    }
    if(r >= n) {
        ans[idx] = max(ans[idx], cnt);
        return;
    }

    if(arr[r][c] && !u[r + c] && !d[r + c + n]) {
        u[r + c] = d[r + c + n] = true;
        backtrack(r, c + 2, cnt + 1);
        u[r + c] = d[r + c + n] = false;
    }

    backtrack(r, c + 2, cnt);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];

    backtrack(0, 0, 0); idx++;
    backtrack(0, 1, 0);

    cout << ans[0] + ans[1];
}