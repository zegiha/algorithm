#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, arr[3], dp_max[2][3], dp_min[2][3];
    int t, j, i, big, small, d;
    const int dx[] = {-1, 0, 1};
    cin >> n;
    for(i = 0; i < 3; i++) {
        cin >> arr[i];
        dp_max[0][i] = dp_min[0][i] = arr[i];
    }
    

    for(i = 1; i < n; i++) {
        for(t = 0; t < 3; t++) cin >> arr[t];
        for(j = 0; j < 3; j++) {
            big = -1;
            small = 2'100'000'000;
            for(d = 0; d < 3; d++) {
                if(0 <= j + dx[d] && j + dx[d] < 3) {
                    big = max(big, dp_max[0][j + dx[d]]);
                    small = min(small, dp_min[0][j + dx[d]]);
                }
            }
            dp_max[1][j] = big + arr[j];
            dp_min[1][j] = small + arr[j];
        }

        for(t = 0; t < 3; t++) {
            dp_max[0][t] = dp_max[1][t];
            dp_min[0][t] = dp_min[1][t];
        }
    }

    big = -1;
    small = 2'100'000'000;
    for(t = 0; t < 3; t++) {
        big = max(big, dp_max[0][t]);
        small = min(small, dp_min[0][t]);
    }

    cout << big << ' ' << small;
}