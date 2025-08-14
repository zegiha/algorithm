#include <iostream>

using namespace std;

int n, arr[20][20], ans = 2'100'000'000;

bool visited[20];
void solve(int cnt, int pos) {
    if(cnt == n/2) {
        int t1 = 0, t2 = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i] == visited[j]) {
                    if(visited[i]) t1 += arr[i][j];
                    else t2 += arr[i][j];
                }
            }
        }

        ans = min(ans, abs(t1 - t2));
        return;
    }

    for(int i = pos + 1; i < n; i++) {
        if(visited[i]) continue;
        
        visited[i] = true;
        solve(cnt + 1, i);
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    solve(0, 0);

    cout << ans;
}
