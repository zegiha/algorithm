#include <iostream>
#include <queue>

using namespace std;
using pii = pair <int, int>;
using ppiipii = pair <pii, pii>;

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int n, m, arr[11][11];
pii r, b, g;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string t; cin >> t;
        for(int j = 0; j < m; j++) {
            if(t[j] == '#') arr[i][j] = -1;
            else if(t[j] == '.') arr[i][j] = 0;
            else if(t[j] == 'O') {
                arr[i][j] = 9;
                g = {i, j};
            } else if(t[j] == 'R') {
                arr[i][j] = 1;
                r = {i, j};
            }
            else {
                arr[i][j] = 2;
                b = {i, j};
            }
        }
    }

    int cnt = 0;
    queue <ppiipii> q;
    q.push({r, b});

    while(!q.empty() && cnt < 10) {
        int size = q.size();
        while(size--) {
            r = q.front().first, b = q.front().second;
            for(int d = 0; d < 4; d++) {
                pii new_r, new_b;
                int cnt1 = 0, cnt2 = 0, nr, nc;
                bool is_r_g = false, is_b_g = false;

                nr = r.first, nc = r.second;
                while(arr[nr + dy[d]][nc + dx[d]] != -1) {
                    nr += dy[d], nc += dx[d];
                    if(arr[nr][nc] == 9) is_r_g = true;
                    cnt1++;
                }
                new_r = {nr, nc};

                nr = b.first, nc = b.second;
                while(arr[nr + dy[d]][nc + dx[d]] != -1) {
                    nr += dy[d], nc += dx[d];
                    if(arr[nr][nc] == 9) is_b_g = true;
                    cnt2++;
                }
                new_b = {nr, nc};

                
            }
        }
        cnt++;
    }
}