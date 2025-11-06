#include <iostream>
#include <vector>

using namespace std;
using db = double;

vector <double> dp[102][102][102];

vector <double> getDp(int r, int y, int b) {
    if(r == y && y == b) return {1.0/3, 1.0/3, 1.0/3};
    if(r == 0) return {0.0, 1.0, 0.0};
    if(y == 0) return {0.0, 0.0, 1.0};
    if(b == 0) return {1.0, 0.0, 0.0};
    if(dp[r][y][b].size() > 0) return dp[r][y][b];

    vector <double> res = {0.0, 0.0, 0.0}, t;
    int cases[][3] = {
        {r-1, y, b},
        {r, y-1, b},
        {r, y, b-1},
    }, total = r*y + r*b + y*b;
    double tt[] = {
        (double)(r*b) / total,
        (double)(r*y) / total,
        (double)(y*b) / total
    };
    for(int ci = 0; ci < 3; ci++) {
        auto c = cases[ci];
        t = getDp(c[0], c[1], c[2]);
        for(int i = 0; i < 3; i++) {
            res[i] += t[i] * tt[ci];
        }
    }

    return dp[r][y][b] = res;
}

void solve() {
    int r, y, b; cin >> r >> y >> b;
    vector <double> ans = getDp(r, y, b);
    for(int i = 0; i < 3; i++) {
        printf("%.12lf ", ans[i]);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
}