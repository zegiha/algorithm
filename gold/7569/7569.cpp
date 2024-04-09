#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int m, n, h, cnt, ans;
vector <vector <vector <int>>> arr;
queue <tuple <int, int, int>> q;

void addToQ(int lv, int row, int col) {
    tuple <int, int, int> tmp;
    if((lv + 1) < h) {
        if(arr[lv + 1][row][col] == 0) {
            arr[lv + 1][row][col] = 2;
            tmp = make_tuple(lv + 1, row, col);
            q.push(tmp);
            cnt--;
        }
    }
    if((lv - 1) >= 0) {
        if(arr[lv - 1][row][col] == 0) {
            arr[lv - 1][row][col] = 2;
            tmp = make_tuple(lv - 1, row, col);
            q.push(tmp);
            cnt--;
        }
    }
    if((row + 1) < n) {
        if(arr[lv][row + 1][col] == 0) {
            arr[lv][row + 1][col] = 2;
            tmp = make_tuple(lv, row + 1, col);
            q.push(tmp);
            cnt--;
        }
    }
    if((row - 1) >= 0) {
        if(arr[lv][row - 1][col] == 0) {
            arr[lv][row - 1][col] = 2;
            tmp = make_tuple(lv, row - 1, col);
            q.push(tmp);
            cnt--;
        }
    }
    if((col + 1) < m) {
        if(arr[lv][row][col + 1] == 0) {
            arr[lv][row][col + 1] = 2;
            tmp = make_tuple(lv, row, col + 1);
            q.push(tmp);
            cnt--;
        }
    }
    if((col - 1) >= 0) {
        if(arr[lv][row][col - 1] == 0) {
            arr[lv][row][col - 1] = 2;
            tmp = make_tuple(lv, row, col - 1);
            q.push(tmp);
            cnt--;
        }
    }
}

int main() {
    cin >> m >> n >> h;
    arr.resize(h + 1);
    for(int lv = 0; lv < h; lv++) {
        arr[lv].resize(n + 1);
        for(int row = 0; row < n; row++) {
            arr[lv][row].resize(m + 1);
            for(int col = 0; col < m; col++) {
                cin >> arr[lv][row][col];
                if(arr[lv][row][col] == 1) {
                    tuple <int, int, int> tmp = make_tuple(lv, row, col);
                    q.push(tmp);
                } else if(arr[lv][row][col] == 0) cnt++;
            }
        }
    }
    while(!q.empty() && cnt > 0) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            tuple <int, int, int> qFront = q.front(); q.pop();
            addToQ(get<0>(qFront), get<1>(qFront), get<2>(qFront));
        }
        ans++;
    }

    if(!cnt) cout << ans;
    else cout << -1;
}