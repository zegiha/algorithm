#include <iostream>

using namespace std;

int n, m, arr[1001][1001];

void solve(int n, int rs, int re, int cs, int ce) {
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "=================  " << "rs : " << rs << ", re : " << rs << ", cs : " << cs << ", ce : " << ce << "  ==================\n";
    if(cs >= ce) {
        solve(n, rs + 1, re - 1, 0, m - 1);
    } else if(rs >= re) {
        return;
    } else {
        arr[rs][cs] = arr[rs][ce] = arr[re][cs] = arr[re][ce] = n;
        solve(n + 1, rs, re, cs + 1, ce - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    solve(1, 0, n - 1, 0, m - 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
