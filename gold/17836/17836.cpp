#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, t;
vector <vector <int>> arr;



int main() {
    cin >> n >> m >> t;
    arr.resize(n + 1);
    for(int i = 0; i < n; i++) {
        arr[i].resize(m + 1);
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }

    queue <pair <int, int>> q;
    int cnt = 0, soardT = 2100000000;
    bool hasS = false;

    q.push(make_pair(0, 0));
    while((cnt <= t) && !q.empty()) {
        
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if((r == (n - 1)) && (c == (m - 1))) {
                cout << cnt;
                return 0;
            }

            if(r + 1 < n) {
                if((arr[r + 1][c] != 1) && (arr[r + 1][c] != -1)) {
                    if(arr[r + 1][c] == 2) {
                        soardT = cnt + ((n - 1) - (r + 1)) + ((m - 1) - c) + 1;
                    }
                    arr[r + 1][c] = -1;
                    q.push(make_pair(r + 1, c));
                }
            }
            if(r - 1 > -1) {
                if((arr[r - 1][c] != 1) && (arr[r - 1][c] != -1)) {
                    if(arr[r - 1][c] == 2) {
                        soardT = cnt + ((n - 1) - (r - 1)) + ((m - 1) - c) + 1;
                    }
                    arr[r - 1][c] = -1;
                    q.push(make_pair(r - 1, c));
                }
            }
            if(c + 1 < m) {
                if((arr[r][c + 1] != 1) && (arr[r][c + 1] != -1)) {
                    if(arr[r][c + 1] == 2) {
                        soardT = cnt + ((n - 1) - r) + ((m - 1) - (c + 1)) + 1;
                    }
                    arr[r][c + 1] = -1;
                    q.push(make_pair(r, c + 1));
                }
            }
            if(c - 1 > -1) {
                if((arr[r][c - 1] != 1) && (arr[r][c - 1] != -1)) {
                    if(arr[r][c - 1] == 2) {
                        soardT = cnt + ((n - 1) - r) + ((m - 1) - (c - 1)) + 1;
                    }
                    arr[r][c - 1] = -1;
                    q.push(make_pair(r, c - 1));
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << endl;
        // } cout << endl;
        if((soardT <= t) && (soardT < cnt)) {
            cout << soardT;
            return 0;
        }
        cnt++;
    }

    if(soardT <= t) {
        cout << soardT;
        return 0;
    }
    cout << "Fail";
}