#include <iostream>
#include <queue>

using namespace std;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
int n, m, arr[601][601], ans;
bool visit[601][601];

bool is_area(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

int main() {
    int dor, doc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            if(c == 'O') arr[i][j] = 0;
            else if(c == 'X') arr[i][j] = -1;
            else if(c == 'I') {
                arr[i][j] = 2;
                dor = i; doc = j;
            }
            else arr[i][j] = 1;
        }
    }

    queue <pair <int, int>> q;

    q.push({dor, doc});
    visit[dor][doc] = true;

    while(!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nr = r + dy[d], nc = c + dx[d];
            if(is_area(nr, nc) && !visit[nr][nc] && arr[nr][nc] != -1) {
                q.push({nr, nc});
                visit[nr][nc] = true;
                if(arr[nr][nc] == 1) {
                    ans++;
                }
            }
        }
    }

    if(ans == 0) cout << "TT";
    else cout << ans;
}