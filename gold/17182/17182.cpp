#include <iostream>
#include <algorithm>

using namespace std;

int n, k, arr[11][11], ans = 2'100'000'000;

bool visit[11];
void make_ans(int prev, int depth, int cnt) {
    if(depth == n) {
        if(ans > cnt) ans = cnt;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visit[i]) {
            visit[i] = true;
            make_ans(i, depth + 1, cnt + arr[prev][i]);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            for(int k = 0; k < n; k++) {
                if(i == k) continue;
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    visit[k] = true;
    make_ans(k, 1, 0);

    cout << ans;
}