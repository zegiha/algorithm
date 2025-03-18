#include <iostream>   
#include <queue>

using namespace std;

struct step {
    int rr;
    int rc;
    int br;
    int bc;
    int cnt;
};

const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

int n, m, arr[11][11];
bool visit[11][11][11][11] = {0, };

void move(int* r, int* c, int* cnt, int d) {
    while(arr[(*r) + dy[d]][(*c) + dx[d]] != -1 && arr[(*r)][(*c)] != 9) {
        (*r) += dy[d];
        (*c) += dx[d];
        (*cnt)++;
    }
}

int main() {
    step initial_data;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') arr[i][j] = -1;
            else if(s[j] == '.') arr[i][j] = 0;
            else if(s[j] == 'O') arr[i][j] = 9;
            else if(s[j] == 'R') {
                initial_data.rr = i;
                initial_data.rc = j;
                arr[i][j] = 1;
            }
            else {
                initial_data.br = i;
                initial_data.bc = j;
                arr[i][j] = 2;
            }
        }
    }

    initial_data.cnt = 0;
    visit[initial_data.rr][initial_data.rc][initial_data.br][initial_data.bc] = true;

    bool sw = true;
    queue <step> q;
    q.push(initial_data);
    while(!q.empty() && sw) {
        int
            rr = q.front().rr,
            rc = q.front().rc,
            br = q.front().br,
            bc = q.front().bc,
            cnt = q.front().cnt;
        q.pop();

        // cout << cnt << '\n';
        
        if(cnt >= 10) break;


        for(int d = 0; d < 4; d++) {
            int nrc = rc, nrr = rr, nbc = bc, nbr = br,
            rcnt = 0, bcnt = 0;
            
            move(&nrr, &nrc, &rcnt, d);
            move(&nbr, &nbc, &bcnt, d);

            if(arr[nbr][nbc] == 9) continue;
            if(arr[nrr][nrc] == 9) {
                cout << 1;
                sw = false;
                break;
            }

            if(nrr == nbr && nrc == nbc) {
                if(rcnt > bcnt) {
                    nrr -= dy[d];
                    nrc -= dx[d];
                } else {
                    nbr -= dy[d];
                    nbc -= dx[d];
                }
            }

            if(!visit[nrr][nrc][nbr][nbc]) {
                visit[nrr][nrc][nbr][nbc] = true;
                step tmp;
                tmp.rr = nrr; tmp.rc = nrc; tmp.br = nbr; tmp.bc = nbc; tmp.cnt = cnt + 1;
                q.push(tmp);
            }
        }
    }

    if(sw) cout << 0;
}